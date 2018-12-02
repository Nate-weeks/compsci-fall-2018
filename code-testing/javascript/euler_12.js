/**Code to solver euler 12 - first triangle number with 500 divisors
November 2018**/

function euler_12(num){
  var answer;
  var factor_count = 0
  i = 0;
  triangle_number = 0;
  while(factor_count <= num){
    factor_count = 0
    i += 1
    triangle_number = triangle_number + i
    for(factor=1;factor<=Math.sqrt(triangle_number);factor+=1){
      if(triangle_number % factor == 0){
        factor_count += 2
      }
      if(factor * factor == triangle_number){
        factor_count -= 1
      }
    }
    answer = triangle_number
  }
  return answer
}

// console.log(euler_12(500))

module.exports = {euler_12}
