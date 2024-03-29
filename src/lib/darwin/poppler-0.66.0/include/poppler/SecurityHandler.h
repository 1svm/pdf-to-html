//========================================================================
//
// SecurityHandler.h
//
// Copyright 2004 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the pdf-to-html project - http://pdf-to-html.freedesktop.org
//
// All changes made under the pdf-to-html project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2012, 2018 Albert Astals Cid <aacid@kde.org>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef SECURITYHANDLER_H
#define SECURITYHANDLER_H

#include "pdf-to-html-config.h"

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "goo/gtypes.h"
#include "Object.h"

class GooString;
class PDFDoc;
struct XpdfSecurityHandler;

//------------------------------------------------------------------------
// SecurityHandler
//------------------------------------------------------------------------

class SecurityHandler {
public:

  static SecurityHandler *make(PDFDoc *docA, Object *encryptDictA);

  SecurityHandler(PDFDoc *docA);
  virtual ~SecurityHandler();

  SecurityHandler(const SecurityHandler &) = delete;
  SecurityHandler& operator=(const SecurityHandler &) = delete;

  // Returns true if the file is actually unencrypted.
  virtual GBool isUnencrypted() { return gFalse; }

  // Check the document's encryption.  If the document is encrypted,
  // this will first try <ownerPassword> and <userPassword> (in
  // "batch" mode), and if those fail, it will attempt to request a
  // password from the user.  This is the high-level function that
  // calls the lower level functions for the specific security handler
  // (requesting a password three times, etc.).  Returns true if the
  // document can be opened (if it's unencrypted, or if a correct
  // password is obtained); false otherwise (encrypted and no correct
  // password).
  GBool checkEncryption(GooString *ownerPassword,
			GooString *userPassword);

  // Create authorization data for the specified owner and user
  // passwords.  If the security handler doesn't support "batch" mode,
  // this function should return NULL.
  virtual void *makeAuthData(GooString *ownerPassword,
			     GooString *userPassword) = 0;

  // Construct authorization data, typically by prompting the user for
  // a password.  Returns an authorization data object, or NULL to
  // cancel.
  virtual void *getAuthData() = 0;

  // Free the authorization data returned by makeAuthData or
  // getAuthData.
  virtual void freeAuthData(void *authData) = 0;

  // Attempt to authorize the document, using the supplied
  // authorization data (which may be NULL).  Returns true if
  // successful (i.e., if at least the right to open the document was
  // granted).
  virtual GBool authorize(void *authData) = 0;

  // Return the various authorization parameters.  These are only
  // valid after authorize has returned true.
  virtual int getPermissionFlags() = 0;
  virtual GBool getOwnerPasswordOk() = 0;
  virtual Guchar *getFileKey() = 0;
  virtual int getFileKeyLength() = 0;
  virtual int getEncVersion() = 0;
  virtual int getEncRevision() = 0;
  virtual CryptAlgorithm getEncAlgorithm() = 0;

protected:

  PDFDoc *doc;
};

//------------------------------------------------------------------------
// StandardSecurityHandler
//------------------------------------------------------------------------

class StandardSecurityHandler: public SecurityHandler {
public:

  StandardSecurityHandler(PDFDoc *docA, Object *encryptDictA);
  ~StandardSecurityHandler();

  GBool isUnencrypted() override;
  void *makeAuthData(GooString *ownerPassword,
			     GooString *userPassword) override;
  void *getAuthData() override;
  void freeAuthData(void *authData) override;
  GBool authorize(void *authData) override;
  int getPermissionFlags() override { return permFlags; }
  GBool getOwnerPasswordOk() override { return ownerPasswordOk; }
  Guchar *getFileKey() override { return fileKey; }
  int getFileKeyLength() override { return fileKeyLength; }
  int getEncVersion() override { return encVersion; }
  int getEncRevision() override { return encRevision; }
  CryptAlgorithm getEncAlgorithm() override { return encAlgorithm; }

private:

  int permFlags;
  GBool ownerPasswordOk;
  Guchar fileKey[32];
  int fileKeyLength;
  int encVersion;
  int encRevision;
  GBool encryptMetadata;
  CryptAlgorithm encAlgorithm;

  GooString *ownerKey, *userKey;
  GooString *ownerEnc, *userEnc;
  GooString *fileID;
  GBool ok;
};

#ifdef ENABLE_PLUGINS
//------------------------------------------------------------------------
// ExternalSecurityHandler
//------------------------------------------------------------------------

class ExternalSecurityHandler: public SecurityHandler {
public:

  ExternalSecurityHandler(PDFDoc *docA, Object *encryptDictA,
			  XpdfSecurityHandler *xshA);
  virtual ~ExternalSecurityHandler();

  virtual void *makeAuthData(GooString *ownerPassword,
			     GooString *userPassword);
  virtual void *getAuthData();
  virtual void freeAuthData(void *authData);
  virtual GBool authorize(void *authData);
  virtual int getPermissionFlags() { return permFlags; }
  virtual GBool getOwnerPasswordOk() { return gFalse; }
  virtual Guchar *getFileKey() { return fileKey; }
  virtual int getFileKeyLength() { return fileKeyLength; }
  virtual int getEncVersion() { return encVersion; }
  virtual int getEncRevision() { return encRevision; }
  virtual CryptAlgorithm getEncAlgorithm() { return encAlgorithm; }

private:

  Object encryptDict;
  XpdfSecurityHandler *xsh;
  void *docData;
  int permFlags;
  Guchar fileKey[16];
  int fileKeyLength;
  int encVersion;
  int encRevision;
  CryptAlgorithm encAlgorithm;
  GBool ok;
};
#endif // ENABLE_PLUGINS

#endif
