// driver program for advent of code 2018
// Nate Weeks dec 2018
// module idea taken from https://markheath.net/post/advent-of-code-2017-day-1

let fs = require('fs');
const getInput = require('./utils')
let day = process.argv.slice(2);
let path = ('./input/day-' + day + '.txt')

if (!fs.existsSync(path)) {
       console.log(`day ${day} not found`);
   } else {
  let text = getInput(path);
  const {part_one, part_two} = require('./day-' + day);

  console.log('part one: ' + part_one(text))
  console.log('part two: ' + part_two(text))
}
