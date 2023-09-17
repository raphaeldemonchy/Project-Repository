#include "Kitchen.hpp"

void Kitchen::newKitchen(int _nbrOfProducers, int ingredientReplacementTime_, int timeMultiplier_)
{
    pid_t pid = fork();
    if (pid == -1) {
        // Error occurred while forking
        std::cerr << "Error: Failed to fork" << std::endl;
        return;
    } else if (pid == 0) {

        // Child process
        ThreadArgs* _threadArgs = new ThreadArgs;
        int cooksPerKitchens = _nbrOfProducers;
        // Créer une socket de communication avec la réception de type PULL

        for (; _nbrOfProducers != 0; _nbrOfProducers--) {
            Thread* _thread = new Thread(_threadArgs);
            _thread->Thread_init(cooksPerKitchens, ingredientReplacementTime_, timeMultiplier_, _commands, fridge, _clock);
            _Producters.push_back(_thread);
        }
        for (int i = 0; i != _Producters.size(); i++)
            _Producters[i]->Thread_join();
            while (true) {
                if (!_commands.empty()) {
                    for (int i = 0; i < _Producters.size(); i++) {
                        Thread* thread = _Producters[i];
                        if (!_commands.empty() && thread->getCommandCount() < 2) {
                            Pizza *command = _commands.back();
                            _commands.pop_back();
                            thread->assignCommand(command);
                        }
                    }
                }
                fridge->regenerateStock(ingredientReplacementTime_);
        exit(0); // Make sure the child process exits when the loop ends
        }
    }
}
void Kitchen::destroyKitchen(){}