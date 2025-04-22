#include <iostream>
#include <array>
#include <chrono>
#include <thread>
#include <string>
#include <random>
#include <atomic>
#include <iomanip>
#include <csignal>
#include <locale>

using namespace std;

//declaring global variables to make this work
atomic<bool> stopAnim(false);
bool russianLang = false;
bool gotQueryfromCli = false;
string query = "";
bool quiet = false;

//function that gives cursor back if ctrl+c pressed
void shukher(int signal){
	if(signal == SIGINT){
		cout << "\033[?25h" << "\n" << flush;
		exit(0);
	}
}

//function that prints smth in terminal to let the user know that programm is still running
void standbyAnim(){
	cout << "\033[?25l";
	while(!stopAnim){
		array<string, 4> animation = {"   ", ".  ", ".. ", "..."};
		if(russianLang){
			for(int i = 0; i < animation.size(); i++){
				if(stopAnim) break;
				cout << "\rПроисходит перебор" << animation[i] << flush;
				this_thread::sleep_for(chrono::milliseconds(500));
			}
		}else{
			for(int i = 0; i < animation.size(); i++){
				if(stopAnim) break;
				cout << "\rProcessing" << animation[i] << flush;
				this_thread::sleep_for(chrono::milliseconds(500));
			}
		}
	}
	cout << "\033[?25h";
}

//main function
void shelf(){
	random_device rd;
	mt19937 gen(rd());
	string alphabet;
	if(russianLang){
		alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	}else{
		alphabet = "abcdefghijklmnopqrstuvwxyz";
	}
	uniform_int_distribution<> dis(0, alphabet.size()-1);
	
  if(!gotQueryfromCli){
	  if(russianLang){
		  cout << "В Вавилонской библиотеке можно найти любую информацию, но это займёт некоторое время. Какое слово Вам нужно найти?\nВведите слово: ";
	  }else{

		  cout << "In Babylon Library you can find any information. But it would take some time. What word do you want to find?\nEnter the word: ";
	  }
	  cin >> query;
  }else{
    if(russianLang){
      cout << "Получено слово как аргумент...\n";
    }else{
      cout << "An argument taken as a word to find...\n";
    }
  }
	
	clock_t start_time = clock();
  
  thread standingBy;
	if(!quiet) standingBy = thread(standbyAnim);

	for(char& c : query){
		c = tolower(c);
	}

	unsigned int attempts = 0;

	while(true){
		string result = "";
		for(int i = 0; i < query.size(); i++){
			result += alphabet[dis(gen)];
			attempts++;
		}
		if(result == query){ //i could move this atrocuty into a function to make the code prettier 
			if(!quiet) stopAnim = true;
			clock_t end_time = clock();
			double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
			int speed = int(attempts/execution_time);
			cout.imbue(locale("en_US.UTF-8"));
			cout << fixed << setprecision(2);
			if(russianLang){
				cout << "\rСлово '" << query <<"' было найдено! Понадобилось перебрать " << attempts <<" букв и "<< execution_time <<" секунд.\nСредняя скорость перебора = " << speed <<" символов в секунду.\n";
			}else{
				cout << "\rThe word '" << query << "' was found!\nIt took " << attempts << " letters and " << execution_time << " seconds!\nAverage combination speed = " << speed << " letters per second.\n";
			}
			break;
		}
	}
	if(!quiet) standingBy.join();
}

int main(int argc, char* argv[]){
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			string arg = argv[i];
		  	if(arg == "--russian" || arg == "-r"){
				russianLang = true;
		  	} else if(arg == "--quiet" || arg == "-q"){
        		quiet = true;
      			}else {
        			gotQueryfromCli = true;
        			query = arg;
      			}

    		}
	}


	signal(SIGINT, shukher);
	shelf();
	return 0;
}
