#!/usr/bin/env node

const { readFile } = require("fs").promises;

readFile("escape_codes.json", "utf8")
  .then(text => {
    console.log(text)
  });
