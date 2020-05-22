const fs = require('fs');
const glob = require('glob');
const path = require('path');
const { pdf-to-html } = require('./index');

const testDirectory = `${__dirname}/../test_docs/`;
const file = `${testDirectory}pdf_1.3_NHS_Constitution.pdf`;

function clean() {
	return new Promise((resolve) => {
		const files = glob.GlobSync(
			`${testDirectory}!(test.txt|pdf_1.3_NHS_Constitution.pdf|pdf_1.3_NHS_Constitution_attached_detach.pdf|pdf_1.7_NHS_Constitution_Handbook.pdf)`
		).found;
		files.forEach((foundFile) => {
			fs.unlinkSync(foundFile);
		});
		resolve('done');
	});
}

describe('Constructor', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should convert PDF file to SVG file with binary path set', async () => {
		const testPath = path.join(
			__dirname,
			'lib',
			'win32',
			'pdf-to-html-0.88.0',
			'bin'
		);
		const pdf-to-html = new pdf-to-html(testPath);
		const options = {
			svgFile: true
		};
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution.svg`;

		await pdf-to-html.pdfToCairo(options, file, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.svg`)
			).toBe(true);
		});
	});
});

describe('pdfAttach function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should attach file to PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const attachmentFile = `${testDirectory}test.txt`;
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution_attached.pdf`;

		await pdf-to-html
			.pdfAttach(undefined, file, attachmentFile, outputFile)
			.then((res) => {
				expect(typeof res).toBe('string');
				expect(
					fs.existsSync(
						`${testDirectory}pdf_1.3_NHS_Constitution_attached.pdf`
					)
				).toBe(true);
			});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfAttach(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			replace: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfAttach(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'replace', expected boolean but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfAttach(options, file).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});

describe('pdfDetach function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should list embedded files', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			listEmbedded: true
		};
		const attachmentFile = `${testDirectory}pdf_1.3_NHS_Constitution_attached_detach.pdf`;

		await pdf-to-html.pdfDetach(options, attachmentFile).then((res) => {
			expect(typeof res).toBe('string');
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfDetach(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			listEmbedded: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfDetach(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'listEmbedded', expected boolean but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfDetach(options, file).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});

describe('pdfFonts function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should examine 3 pages of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToExamine: 1,
			lastPageToExamine: 3
		};
		await pdf-to-html.pdfFonts(options, file).then((res) => {
			expect(typeof res).toBe('string');
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfFonts(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToExamine: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfFonts(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToExamine', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfFonts(options, file).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});

describe('pdfImages function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should accept options and list all images in file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			pngFile: true
		};

		await pdf-to-html.pdfImages(options, file, `file_prefix`).then((res) => {
			expect(typeof res).toBe('string');
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfImages(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if PDF file missing', async () => {
		const pdf-to-html = new pdf-to-html();

		expect.assertions(1);
		await pdf-to-html.pdfImages(undefined, undefined).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 'test',
			lastPageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfImages(options, undefined).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToConvert', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			middlePageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfImages(options, undefined).catch((err) => {
			expect(err.message).toEqual(
				"Invalid option provided 'middlePageToConvert'"
			);
		});
	});
});

describe('pdfInfo function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should list info of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const attachmentFile = `${testDirectory}pdf_1.3_NHS_Constitution_attached_detach.pdf`;

		await pdf-to-html.pdfInfo(undefined, attachmentFile).then((res) => {
			expect(typeof res).toBe('string');
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfInfo(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfInfo(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToConvert', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfInfo(options, file).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});

describe('pdfSeparate function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should extract 3 pages from PDF file to new files', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToExtract: 1,
			lastPageToExtract: 3
		};
		const outputPattern = `${testDirectory}pdf_1.3_NHS_Constitution-extract-%d.pdf`;

		await pdf-to-html.pdfSeparate(options, file, outputPattern).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(
					`${testDirectory}pdf_1.3_NHS_Constitution-extract-1.pdf`
				)
			).toBe(true);
			expect(
				fs.existsSync(
					`${testDirectory}pdf_1.3_NHS_Constitution-extract-2.pdf`
				)
			).toBe(true);
			expect(
				fs.existsSync(
					`${testDirectory}pdf_1.3_NHS_Constitution-extract-3.pdf`
				)
			).toBe(true);
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfSeparate(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToExtract: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfSeparate(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToExtract', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfSeparate(options, file).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});

describe('pdfToCairo function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should convert PDF file to SVG file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			svgFile: true
		};
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution.svg`;

		await pdf-to-html.pdfToCairo(options, file, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.svg`)
			).toBe(true);
		});
	});

	test('Should accept options and only process 2 pages of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 1,
			lastPageToConvert: 2,
			svgFile: true
		};
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution.svg`;

		await pdf-to-html.pdfToCairo(options, file, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.svg`)
			).toBe(true);
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfToCairo(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if no format option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();

		expect.assertions(1);
		await pdf-to-html.pdfToCairo(undefined, file).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			pdfFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToCairo(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'pdfFile', expected boolean but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToCairo(options, file).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});

describe('pdfToHtml function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should convert PDF file to HTML file', async () => {
		const pdf-to-html = new pdf-to-html();

		await pdf-to-html.pdfToHtml(undefined, file).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.html`)
			).toBe(true);
		});
	});

	test('Should accept options and only process 2 pages of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 1,
			lastPageToConvert: 2
		};

		await pdf-to-html.pdfToHtml(options, file).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.html`)
			).toBe(true);
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfToHtml(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if PDF file missing', async () => {
		const pdf-to-html = new pdf-to-html();

		expect.assertions(1);
		await pdf-to-html.pdfToHtml(undefined, undefined).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 'test',
			lastPageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToHtml(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToConvert', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			middlePageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToHtml(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid option provided 'middlePageToConvert'"
			);
		});
	});
});

describe('pdfToPpm function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should accept options and only process 1 page of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 1,
			lastPageToConvert: 1
		};

		await pdf-to-html
			.pdfToPpm(options, file, `${testDirectory}pdf_1.3_NHS_Constitution`)
			.then((res) => {
				expect(typeof res).toBe('string');
				expect(
					fs.existsSync(
						`${testDirectory}pdf_1.3_NHS_Constitution-01.ppm`
					)
				).toBe(true);
			});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfToPpm(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if PDF file missing', async () => {
		const pdf-to-html = new pdf-to-html();

		expect.assertions(1);
		await pdf-to-html.pdfToPpm(undefined, undefined).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 'test',
			lastPageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToPpm(options, undefined).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToConvert', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			middlePageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToPpm(options, undefined).catch((err) => {
			expect(err.message).toEqual(
				"Invalid option provided 'middlePageToConvert'"
			);
		});
	});
});

describe('pdfToPs function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should convert PDF file to PS file', async () => {
		const pdf-to-html = new pdf-to-html();
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution.ps`;

		await pdf-to-html.pdfToPs(undefined, file, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.ps`)
			).toBe(true);
		});
	});

	test('Should accept options and only process 2 pages of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution.ps`;
		const options = {
			firstPageToConvert: 1,
			lastPageToConvert: 2
		};

		await pdf-to-html.pdfToPs(options, file, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.ps`)
			).toBe(true);
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfToPs(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if PDF file missing', async () => {
		const pdf-to-html = new pdf-to-html();

		expect.assertions(1);
		await pdf-to-html.pdfToPs(undefined, undefined).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 'test',
			lastPageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToPs(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToConvert', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			middlePageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToPs(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid option provided 'middlePageToConvert'"
			);
		});
	});
});

describe('pdfToText function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should convert PDF file to Text file', async () => {
		const pdf-to-html = new pdf-to-html();
		const outputFile = `${testDirectory}pdf_1.3_NHS_Constitution.txt`;

		await pdf-to-html.pdfToText(undefined, file, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.txt`)
			).toBe(true);
		});
	});

	test('Should accept options and only process 2 pages of PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 1,
			lastPageToConvert: 2
		};

		await pdf-to-html.pdfToText(options, file).then((res) => {
			expect(typeof res).toBe('string');
			expect(
				fs.existsSync(`${testDirectory}pdf_1.3_NHS_Constitution.txt`)
			).toBe(true);
		});
	});

	test('Should return an Error object if file passed not PDF format', async () => {
		const pdf-to-html = new pdf-to-html();
		const testTxtFile = `${testDirectory}test.txt`;

		expect.assertions(1);
		await pdf-to-html.pdfToText(undefined, testTxtFile).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if PDF file missing', async () => {
		const pdf-to-html = new pdf-to-html();

		expect.assertions(1);
		await pdf-to-html.pdfToText(undefined, undefined).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			firstPageToConvert: 'test',
			lastPageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToText(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'firstPageToConvert', expected number but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const options = {
			middlePageToConvert: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfToText(options, file).catch((err) => {
			expect(err.message).toEqual(
				"Invalid option provided 'middlePageToConvert'"
			);
		});
	});
});

describe('pdfUnite function', () => {
	afterAll(async () => {
		await clean();
	});

	test('Should merge two separate PDF files into a new single PDF file', async () => {
		const pdf-to-html = new pdf-to-html();
		const files = [
			file,
			`${testDirectory}pdf_1.7_NHS_Constitution_Handbook.pdf`
		];
		const outputFile = `${testDirectory}united.pdf`;
		await pdf-to-html.pdfUnite(undefined, files, outputFile).then((res) => {
			expect(typeof res).toBe('string');
			expect(fs.existsSync(`${testDirectory}united.pdf`)).toBe(true);
		});
	});

	test('Should return an Error object if a PDF file and non-PDF file are attempted to be merged', async () => {
		const pdf-to-html = new pdf-to-html();
		const files = [
			`${testDirectory}test.txt`,
			`${testDirectory}pdf_1.7_NHS_Constitution_Handbook.pdf`
		];

		expect.assertions(1);
		await pdf-to-html.pdfUnite(undefined, files).catch((err) => {
			expect(err.message.substring(0, 15)).toBe('Command failed:');
		});
	});

	test('Should return an Error object if invalid value types provided for an option are passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const files = [
			file,
			`${testDirectory}pdf_1.7_NHS_Constitution_Handbook.pdf`
		];
		const options = {
			printVersionInfo: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfUnite(options, files).catch((err) => {
			expect(err.message).toEqual(
				"Invalid value type provided for option 'printVersionInfo', expected boolean but recieved string"
			);
		});
	});

	test('Should return an Error object if invalid option is passed to function', async () => {
		const pdf-to-html = new pdf-to-html();
		const files = [
			file,
			`${testDirectory}pdf_1.7_NHS_Constitution_Handbook.pdf`
		];
		const options = {
			wordFile: 'test'
		};

		expect.assertions(1);
		await pdf-to-html.pdfUnite(options, files).catch((err) => {
			expect(err.message).toEqual("Invalid option provided 'wordFile'");
		});
	});
});
