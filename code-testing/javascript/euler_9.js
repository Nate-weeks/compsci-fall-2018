/** Code to solve euler 9 by Nate Weeks
November 2018

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.**/

function euler_9(){
  var answer;
  for(let a=2; a<1000; a++){
    for(let b=2; b<1000; b++){
      let c = Math.sqrt(a*a + b*b)
      if(a + b + c == 1000){
        answer = a*b*c
      }
    }
  }
  return answer
}

console.log(euler_9())

module.exports = {euler_9}
