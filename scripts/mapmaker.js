#!/usr/bin/env node

const { readFile } = require("fs").promises;

readFile("escape_codes.json", "utf8").then(text => {
  const obj = JSON.parse(text);

  console.log("static std::map<std::string, std::string> m {");
  const esc_codes = Object.keys(obj).filter(key => key.endsWith(';'));
  esc_codes.forEach(key => {
    const props = obj[key];
    const characters = props.characters;
    console.log(`    {"${characters}", "${key}"},`);
  });
  console.log("};");

});
