const bible = require("./termble_data/termble_data.json");

let bookName;
let chapter;
let verse;

// get args
setArgs(process.argv.slice(2));
getVerse(bookName, chapter, verse);

/**
 * Get the book name, chapter and verse from the inputted arguments
 * @param {*} args 
 */
function setArgs(args) {
    // set book name
    let following;
    if (Number.isInteger(parseInt(args[0]))) {
        following = 2;
        bookName = args[0] + " " + args[1];
    } else {
        following = 1;
        bookName = args[0];
    }

    // set chapter & verse
    chapter = args[following].split(":")[0];
    verse = args[following].split(":")[1];
}

/**
 * Get the verse content from the arguments
 * @param {*} bookName - the book name
 * @param {*} chapterName - the chapter name
 * @param {*} verseName - the verse name
 * @returns 
 */
function getVerse(bookName, chapterName, verseName) {
    // get book
    const book = bible.find(b => b.name.toLowerCase() === bookName.toLowerCase());

    // if book isn't found
    if (!book) {
        console.log("Book not found.");
        return;
    }

    // get chapter
    const chapter = book.chapters[parseInt(chapterName - 1)];
    
    // if chapter isn't found
    if (!chapter) {
        console.log("Chapter not found.");
        return;
    }

    // get verse
    const verse = chapter[parseInt(verseName - 1)];

    // if verse isn't found
    if (!verse) {
        console.log("Verse not found.");
        return;
    }

    // log
    console.log(`\n-- ${book.name} ${chapterName}:${verseName} (KJV) --\n\n${verse}\n`);
}