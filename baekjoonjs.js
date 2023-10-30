//라인을 읽기위한 모듈
const readline = require("readline");

//입출력 인터페이스
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on("line", (line) => {
    // 한 줄씩 입력받은 후 실행할 코드
    // 입력된 값은 line에 저장된다.
    rl.close(); // 필수!! close가 없으면 입력을 무한히 받는다.
});
rl.on('close', () => {
    // 입력이 끝난 후 실행할 코드
        process.exit();
})


//공백을 기준으로 값 입력받는 방법
let input = []
 
rl.on("line", (line) => {
    input = line.split(' ').map(el => parseInt(el)); // 1 2 3 4
    rl.close();
});
 
rl.on('close', () => {
    input.forEach(el => {
        console.log(el);
    })
    process.exit();
})
 
// 입력
// 1 2 3
 
// 출력
// 1
// 2
// 3

//여러 줄 입력받기
rl.on("line", (line) => {
    input.push(line);
});
 
rl.on('close', () => {
    console.log(input);
    process.exit();
})
 
// 입력
// 1
// 2
// a
// b
 
 
// 출력 
// ['1', '2', 'a', 'b']

//공백이 포함된 문자 여러줄 입력받기
rl.on("line", (line) => {
    input.push(line.split(' ').map(el => parseInt(el)));
});
 
rl.on('close', () => {
    console.log(input);
    process.exit();
})
 
// 입력
// 1 2 3
// 4 5 6
 
// 출력 
// [[1, 2, 3], [4, 5, 6]]