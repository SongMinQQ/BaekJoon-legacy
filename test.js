const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on("line", (line) => {
    input = parseInt(line);
    rl.close();
});
rl.on('close', () => {
        solution(input);
        process.exit();
})

const solution = (input) => {
    solve(input);
    // console.log(input);
}

const solve =(input) => {
    if((input >= 4)&&(input <= 1000)){
        let j = input / 4;
        if(input % 4 === 0){
            for(let i=1; i <= j; i++){
                process.stdout.write(`long `);
            }
            process.stdout.write('int');
        }
        
    }
    else
        process.exit();
}