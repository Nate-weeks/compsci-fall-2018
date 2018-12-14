// code by nate weeks to solve AOC2018 day 1
// December 2018

function part_one(text){
  const result = text.reduce((total, amount) => (
    total + parseInt(amount)
  ), 0);
  return result;
}

function part_two(text){
  let total = 0;
  let hash = {};
  let i = 0;
  while(i != -1){
    for(j=0; j<text.length; j++){
      total += parseInt(text[j]);
      if(hash[total]){
        i = -1;
        break;
      }
      hash[total] = total;
    }
  }
  return total;
}

module.exports = {part_one, part_two};
