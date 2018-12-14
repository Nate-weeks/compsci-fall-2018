// utility functions for advent of code by Nate Weeks

let fs = require('fs');

// reads a file and splits it into an array of strings
function getInput(input){
  let text = fs.readFileSync(input)
                .toString()
                .split('\n')
                .map(s => s.replace(/\r$/, ''))
                .filter(s => s.length > 0);
  return text;
  }

module.exports = getInput;
