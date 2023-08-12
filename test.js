const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on("line", (line) => {
    rl.close();
});
rl.on('close', () => {
        console.log(rl.input) 
        process.exit();
})