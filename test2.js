const { log } = require('console');
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});
let input;
let count = 4;
rl.on('line', (line) => {
    // console.log(line);
    input = Number(line);
    // if(input > 50 || input < 1){
    //     return;
    // }
}).on('close', () => {
    console.log("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
    console.log('"재귀함수가 뭔가요?"');
    console.log('"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.');
    console.log('마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.');
    console.log('그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."');
    solution(1, 1, input);
    console.log("라고 답변하였지.");
    process.exit(0);
});
function solution(start, count, input) {
  // console.log(input);
  
  if (start === input) {
    console.log('____'.repeat(count) + '"재귀함수가 뭔가요?"');
    console.log('____'.repeat(count) + '"재귀함수는 자기 자신을 호출하는 함수라네"');
    console.log('____'.repeat(count) + "라고 답변하였지.");
    // count /= 2;
    return "";
  }
  else {
      console.log('____'.repeat(count) + '"재귀함수가 뭔가요?"');
      console.log('____'.repeat(count) + '"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.');
      console.log('____'.repeat(count) + '마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.');
      console.log('____'.repeat(count) + '그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."');
      // input - 1 *= 2;
      solution(start+1, count+1, input);
      console.log('____'.repeat(count) + "라고 답변하였지.");
      // input - 1 /= 2;
  }
    
}