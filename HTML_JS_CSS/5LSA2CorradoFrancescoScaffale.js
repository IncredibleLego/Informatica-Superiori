var books = [{title: "Verde",stars: 4, author: "John", colour: {red: 0, green: 255, blue:0}, collocazione: {x: 10, y: 20}, recommended: false}, 

{title: "Bianco",stars: 3, author: "Ben", colour: {red: 255, green: 255, blue:255}, collocazione: {x: 110, y: 20}, recommended: false}, 
{title: "Rosso",stars: 1, author: "Luke", colour: {red: 255, green: 0, blue:0}, collocazione: {x: 210, y: 20}, recommended: false}, 
{title: "Viola",stars: 2, author: "Leila", colour: {red: 200, green: 0, blue: 200}, collocazione: {x: 10, y: 140}, recommended: false}, 
{title: "Giallo",stars: 1, author: "Ian", colour: {red: 255, green: 255, blue: 0}, collocazione: {x: 110, y: 140}, recommended: false}];

// draw shelf
fill(173, 117, 33);
rect(0, 120, width, 10);
rect(0, 240, width, 10);

// draw one book
for(var j=0; j<books.length; j++){
    fill(books[j].colour.red, books[j].colour.green, books[j].colour.blue);
    rect(books[j].collocazione.x, books[j].collocazione.y, 90, 100);
    fill(0, 0, 0);
    text(books[j].title, 5+books[j].collocazione.x, 10+books[j].collocazione.y, 70, 100);
    text(books[j].author, 5+books[j].collocazione.x, 30+books[j].collocazione.y, 70, 100);
    for (var i = 0; i< books[j].stars; i++) {
        image(getImage("cute/Star"), 9+books[j].collocazione.x+i*20, 70+books[j].collocazione.y, 20, 30);
    }
}
