#!/usr/bin/env node

const { readFile } = require("fs").promises;

readFile("escape_codes.json", "utf8").then(text => {
  const obj = JSON.parse(text);

  console.log("static std::map<uint32_t, std::string> m {");

  // Some Unicode characters are made up of several codepoints, and can be
  // interpreted with or without a semicolon. To avoid duplicates, and to
  // keep this first version simple, we only want the unique entries that
  // are made up of single codepoints.
  //
  const esc_codes = Object.keys(obj).filter(key => key.endsWith(';'));

  esc_codes.forEach(key => {
    const props = obj[key];
    const codepoints = props.codepoints;
    if (codepoints.length === 1 ) {
      console.log(`    {${codepoints}, "${key}"},`);
    }
  });

  console.log("};");
});
