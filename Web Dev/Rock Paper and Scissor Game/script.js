let human_choice;

function random_number_selector(){

    let randomNum = Math.random();

    if (randomNum >= 0 && randomNum < 0.33) {
        return "Rock";
    }
    else if (randomNum >= 0.33 && randomNum < 0.66) {
        return "Paper";
    }
    else {
        return "Scissor";
    }
}

let computer_score = 0;
let human_score = 0;

let live_score_text = document.querySelector(".live-score-text");
let you_score_number = document.querySelector(".you-score-number");
let computer_score_number = document.querySelector(".computer-score-number");

function play_game(){
    let computer_choice = random_number_selector();
    
    if(human_choice === computer_choice){
        live_score_text.innerHTML = `<span class="draw">Draw!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
    }

    else if(human_choice === "Rock"){
        if(computer_choice === "Paper"){
            live_score_text.innerHTML = `<span class="comp-won">Computer Won!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
            computer_score += 1;
            computer_score_number.textContent = `${computer_score}`
        }
        else if(computer_choice === "Scissor"){
            live_score_text.innerHTML = `<span class="you-won">You Won!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
            human_score += 1;
            you_score_number.textContent = `${human_score}`
        }
    }

    else if(human_choice === "Paper"){
        if(computer_choice === "Scissor"){
            live_score_text.innerHTML = `<span class="comp-won">Computer Won!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
            computer_score += 1;
            computer_score_number.textContent = `${computer_score}`
        }
        else if(computer_choice === "Rock"){
            live_score_text.innerHTML = `<span class="you-won">You Won!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
            human_score += 1;
            you_score_number.textContent = `${human_score}`
        }
    }

    else if(human_choice === "Scissor"){
        if(computer_choice === "Rock"){
            live_score_text.innerHTML = `<span class="comp-won">Computer Won!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
            computer_score += 1;
            computer_score_number.textContent = `${computer_score}`
        }
        else if(computer_choice === "Paper"){
            live_score_text.innerHTML = `<span class="you-won">You Won!!</span> , You chose ${human_choice} and Computer chose ${computer_choice}`
            human_score += 1;
            you_score_number.textContent = `${human_score}`
        }
    }
}

function game_reset(){
    human_score = 0;
    you_score_number.textContent = `${human_score}`;
    computer_score = 0;
    computer_score_number.textContent = `${computer_score}`;
    live_score_text.textContent = "Start !!!";
}

function final_score(){
    alert(`Final Score:
        You: ${human_score}
        Computer: ${computer_score}`);
    game_reset();
}