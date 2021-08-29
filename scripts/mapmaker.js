#!/usr/bin/env node

const { readFile } = require("fs").promises;

readFile("escape_codes.json", "utf8").then(text => {
  const jsonObj = JSON.parse(text);
  const englishHello = jsonObj.english;
  console.log(englishHello);
});
