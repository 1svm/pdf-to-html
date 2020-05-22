# pdf-to-html

> Promise-based node.js wrapper for the pdf-to-html PDF rendering library

## Intro

The pdf-to-html module was created out of a need for a PDF-to-HTML conversion module to convert clinical documents in PDF format to HTML.

## Installation

Install using [`yarn`](https://yarnpkg.com/en/package/pdf-to-html):

```bash
yarn add pdf-to-html
```

Or [`npm`](https://www.npmjs.com/package/pdf-to-html):

```bash
npm install pdf-to-html
```

pdf-to-html's test scripts use yarn commands.

### Linux support

Windows and OSX/Darwin binaries are provided with this repository.
For Linux users, you will need to download the `pdf-to-html-data` and `pdf-to-html-utils` binaries seperately.

An example of downloading the binaries on a Debian system:

```
sudo apt-get install pdf-to-html-data
sudo apt-get install pdf-to-html-utils
```

Once they have been installed you will need to pass the `pdf-to-html-utils` installation directory in as parameters to an instance of the pdf-to-html class:

```js
const { pdf-to-html } = require('pdf-to-html');
const pdf-to-html = new pdf-to-html('./usr/bin');
```

## API

```js
const { pdf-to-html } = require('pdf-to-html');
```

[API Documentation can be found here](https://github.com/shivammalhotraone/pdf-to-html/blob/master/API.md)

## Examples

### pdf-to-html.pdfToCairo

`options` object requires atleast one of the following to be set: `jpegFile`; `pdfFile`; `pngFile`; `psFile`; `svgFile`; `tiffFile`.

Example of calling pdf-to-html.pdfToCairo with a promise, to convert only the first and second page of a PDF file to PNG:

```js
const { pdf-to-html } = require('pdf-to-html');

const file = 'test_document.pdf';
const pdf-to-html = new pdf-to-html();
const options = {
	firstPageToConvert: 1,
	lastPageToConvert: 2,
	pngFile: true
};

await pdf-to-html.pdfToCairo(options, file).then((res) => {
	console.log(res);
});
```

### pdf-to-html.pdfToHtml

Every field of the `options` object is entirely optional.

Example of calling pdf-to-html.pdfToHtml with a promise:

```js
const { pdf-to-html } = require('pdf-to-html');

const file = 'test_document.pdf';
const pdf-to-html = new pdf-to-html();
const options = {
	firstPageToConvert: 1,
	lastPageToConvert: 2
};

await pdf-to-html.pdfToHtml(options, file).then((res) => {
	console.log(res);
});
```

### pdf-to-html.pdfToText

Every field of the `options` object is entirely optional.

Example of calling pdf-to-html.pdfToText with a promise:

```js
const { pdf-to-html } = require('pdf-to-html');

const file = 'test_document.pdf';
const pdf-to-html = new pdf-to-html();
const options = {
	firstPageToConvert: 1,
	lastPageToConvert: 2
};

await pdf-to-html.pdfToText(options, file).then((res) => {
	console.log(res);
});
```