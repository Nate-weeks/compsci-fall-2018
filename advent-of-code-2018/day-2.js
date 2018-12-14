// code by nate weeks to solve AOC2018 day 2
// December 2018

// function to split matching letters using regex and populate an array of
// duplicate letters for a given string
function howManyRepeated(str){
  let sum = 0;
  const strArr = str.toLowerCase().split("").sort().join("").match(/(.)\1+/g);
  return strArr;
}

function part_one(input){
  let checksum = 0;
  let number_that_repeated_twice = 0
  let number_that_repeated_thrice = 0
  input.forEach(function(str){
    let repeated = howManyRepeated(str);
    let repeat_twice = 0;
    let repeat_thrice = 0;
    for(i=0; i<repeated.length; i++){
      if(repeated[i].length == 2){
        repeat_twice = 1;
      } else if(repeated[i].length == 3){
        repeat_thrice = 1;
      }
    }
    number_that_repeated_twice += repeat_twice;
    number_that_repeated_thrice += repeat_thrice;
  })
  console.log(number_that_repeated_thrice)
  checksum = number_that_repeated_twice * number_that_repeated_thrice
  return checksum
}

function part_two(input){
  let sum = 0;
  let string1 = [];
  let string2 = [];
  split_strings = input.map(string => string.split(''))
  for(i=0;i<split_strings.length;i++){
    for(j=i+1;j<split_strings.length;j++){
      sum = 0;
      for(k=0;k<split_strings[i].length;k++){
        if(split_strings[i][k] == split_strings[j][k]){
          sum += 1;
        }
      }
      if(sum == split_strings[0].length - 1){
        string1 = split_strings[i]
        string2 = split_strings[j]
      }
    }
  }
  console.log(string1)
  console.log(string2)
  for(i=0;i<string1.length;i++){
    if(string1[i] != string2[i]){
      string1.splice(i, 1)
      break
    }
  }
  console.log(string1)
  let answer = string1.join("")
  return answer;
}

module.exports = {part_one, part_two}
