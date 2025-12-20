#include<stdio.h>
#include<ctype.h>   //For isdigit()
#include <stdlib.h>  // For Clear Screen >> system("cls");

int main(){

    printf("\n");
    printf("====================================================================================================\n");
    printf("----------ROUND ROBIN ALGORITHM----------\n");
    printf("CS-407 : Operating Systems\n");
    printf("====================================================================================================\n");
    printf("\n");
    
    char choice;
    while(1){

        while(1){
        
            printf("=============================\n");
            printf("Please Select an Option:-\n");
            printf("1. Without Arrival Time.\n");
            printf("2. With Arrival Time.\n");
            printf("3. End the Program.\n");
            printf("Input(1-3) : ");
            scanf(" %c", &choice);   //The blank space before the %c is there for a reason. When scanf takes an input char from the user, there is also a \n buffer because of which the invalid_____ message prints twice.
            
            if(!isdigit(choice)){
                
                system("cls");
                printf("Invalid Input. Please Try Again\n");
            }
            else{

                break;
            }
        }

        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Option 1>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        if(choice == '1'){  
            
            system("cls");
            printf("\n<<<<<<<<<<<<<<<ROUND ROBIN ALGORITHM WITHOUT ARRIVAL TIME>>>>>>>>>>>>>>\n\n");

            //---------------Number of Processes---------------

            int pN,maxProcesses = 20;
            while(1){
                
                printf("===========Number of Processes=========\n");
                printf("Enter the Number of Processes(Max : %d) : ", maxProcesses);
                scanf("%d", &pN);

                if(pN > maxProcesses){       //To set process limit
                    
                    system("cls");
                    printf("Maximum Process limit is %d.Try Again.\n", maxProcesses);
                }
                else if(pN < 0){

                    system("cls");
                    printf("Number of processes must be in positive.\n");
                }
                else{

                    system("cls");
                    break;
                }
            }

            //Variables
            int burstTime[pN], remainingTime[pN], turnAroundTime[pN] , waitingTime[pN];

            //---------------Burst Time---------------

            printf("===========Burst Time=========\n");
            for(int i=0; i<pN; i++){
                
                while(1){     //Just in case if someone inputs burst time in negative.
                    
                    printf("----------Process # %d----------\n", i+1);
                    printf("Enter the burst time  of P%d: ", i+1);
                    scanf("%d", &burstTime[i]);

                    remainingTime[i] = burstTime[i];
                    turnAroundTime[i] = 0;

                    if(burstTime[i] < 0){

                        system("cls");
                        printf("Burst Time must be >= 0. Try Again.\n");
                    }
                    else{
                        
                        system("cls");
                        break;
                    }
                }
            }
    
            //---------------Quantum Time---------------

            int quantumT;
            while(1){

                printf("===========Quantum Time=========\n");
                printf("Enter the Quantum Time : ");
                scanf("%d", &quantumT);

                if(quantumT <= 0){

                    system("cls");
                    printf("Quantum Time must be greater than 0. Try Again.\n");
                }
                else{

                    system("cls");
                    break;
                }
            }
            
            //---------------Table---------------

            printf("NUMBER OF PROCESSES : %d\n", pN);
            printf("QUANTUM TIME : %d\n", quantumT);
            printf("====================Table==================\n");
            printf("Process \t BurstTime\n");

            for(int i=0; i<pN; i++){
                
                printf("P%d \t\t %d\n", i+1, burstTime[i]);
            }

            //---------------Gant Chart---------------

            printf("====================Gant Chart==================\n");
            int processIndex = -1, currentTime = 0 , execTime = 0, completedProcess = 0;  

            while(completedProcess < pN){        //For Gant Chart

                processIndex = (processIndex + 1) % pN;

                if(remainingTime[processIndex] == 0){

                    continue;  // Skip to next process
                }

                if(remainingTime[processIndex]<quantumT){

                    execTime = remainingTime[processIndex];
                }
                else{

                    execTime = quantumT;
                }

                remainingTime[processIndex] -= execTime;
                printf("P%d    || I.T : %d-%d    || R.T : %d\n", processIndex+1, currentTime, currentTime+execTime , remainingTime[processIndex]);
                currentTime += execTime;
                
                if(remainingTime[processIndex] == 0){
                    
                    turnAroundTime[processIndex] = currentTime;

                    waitingTime[processIndex] = turnAroundTime[processIndex] - burstTime[processIndex];
                    completedProcess++;
                }
            }

            //---------------Waiting & TurnAround Time---------------

            printf("===========Waiting & TurnAround Time=========\n");
            float totalTAT = 0, totalWT = 0;    //To calculate total turnaround and waiting time

            for(int i=0; i<pN; i++){

                printf("P%d   || TA.T : %d    || W.T : %d\n", i+1, turnAroundTime[i], waitingTime[i]);

                totalTAT += turnAroundTime[i];
                totalWT += waitingTime[i];
            }

            //---------------Average Waiting & TurnAround Time---------------

            printf("===========Average Waiting & TurnAround Time=========\n");

            printf("Total turnaround Time : %f\n", totalTAT);
            printf("Total Waiting Time : %f\n\n", totalWT/pN);
            printf("Average turnaround Time : %f\n", totalTAT/pN);
            printf("Average Waiting Time : %f\n", totalWT/pN);
        }

        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Option 2>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        else if(choice == '2'){     
            
            system("cls");
            printf("\n<<<<<<<<<<<<<<<ROUND ROBIN ALGORITHM WITH ARRIVAL TIME>>>>>>>>>>>>>>\n\n");

            //---------------Number of Processes---------------

            int pN,maxProcesses = 20;
            while(1){
                
                printf("===========Number of Processes=========\n");
                printf("Enter the Number of Processes(Max : %d) : ", maxProcesses);
                scanf("%d", &pN);

                if(pN > maxProcesses){       //To set process limit
                    
                    system("cls");
                    printf("Maximum Process limit is %d.Try Again.\n", maxProcesses);
                }
                else if(pN < 0){

                    system("cls");
                    printf("Number of processes must be in positive.\n");
                }
                else{

                    system("cls");
                    break;
                }
            }

            //Variables
            int burstTime[pN], remainingTime[pN], turnAroundTime[pN] , waitingTime[pN], arrivalTime[pN];

            //---------------Burst Time---------------

            printf("===========Burst Time=========\n");
            for(int i=0; i<pN; i++){

                while(1){     //Just in case if someone inputs burst time in negative.

                    printf("----------Process # %d----------\n", i+1);
                    printf("Enter the burst time  of P%d: ", i+1);
                    scanf("%d", &burstTime[i]);
                    printf("Enter the arrival time  of P%d: ", i+1);
                    scanf("%d", &arrivalTime[i]);

                    remainingTime[i] = burstTime[i];
                    turnAroundTime[i] = 0;

                    if(burstTime[i] < 0 || arrivalTime[i] < 0){

                        system("cls");
                        printf("Burst Time and Arrival Time must be >= 0. Try Again.\n");
                    }
                    else{
                        
                        system("cls");
                        break;
                    }
                }
            }
    
            //---------------Quantum Time---------------

            int quantumT;
            while(1){

                printf("===========Quantum Time=========\n");
                printf("Enter the Quantum Time : ");
                scanf("%d", &quantumT);

                if(quantumT <= 0){

                    system("cls");
                    printf("Quantum Time must be greater than 0. Try Again.\n");
                }
                else{

                    system("cls");
                    break;
                }
            }
            
            //---------------Table---------------

            printf("NUMBER OF PROCESSES : %d\n", pN);
            printf("QUANTUM TIME : %d\n", quantumT);
            printf("====================Table==================\n");
            printf("Process \t BurstTime \t ArrivalTime\n");

            for(int i=0; i<pN; i++){
                
                printf("P%d \t\t %d \t\t %d\n", i+1, burstTime[i], arrivalTime[i]);
            }

            //---------------Gant Chart---------------

            printf("====================Gant Chart==================\n");
            int currentTime = 0 , execTime = 0, completedProcess = 0;

            while(completedProcess < pN){ 

                int foundProcess = 0;

                for(int i=0; i<pN; i++){
                    
                    if(arrivalTime[i] <= currentTime && remainingTime[i] > 0){
                        
                        foundProcess = 1;
                        
                        if(remainingTime[i]<quantumT){
                            execTime = remainingTime[i];
                        }
                        else{
                            execTime = quantumT;
                        }
                        
                        remainingTime[i] -= execTime;
                        printf("P%d    || I.T : %d-%d    || R.T : %d\n", i+1, currentTime, currentTime+execTime , remainingTime[i]);
                        currentTime += execTime;
                        
                        if(remainingTime[i] == 0){
                            
                            turnAroundTime[i] = currentTime - arrivalTime[i];
                            waitingTime[i] = turnAroundTime[i] - burstTime[i];
                            completedProcess++;
                        }
                    }
                }

                if(foundProcess == 0){

                    currentTime++;
                }
            }

            //---------------Waiting & TurnAround Time---------------

            printf("===========Waiting & TurnAround Time=========\n");
            float totalTAT = 0, totalWT = 0;    //To calculate total turnaround and waiting time

            for(int i=0; i<pN; i++){

                printf("P%d   || TA.T : %d    || W.T : %d\n", i+1, turnAroundTime[i], waitingTime[i]);

                totalTAT += turnAroundTime[i];
                totalWT += waitingTime[i];
            }

            //---------------Average Waiting & TurnAround Time---------------

            printf("===========Average Waiting & TurnAround Time=========\n");
            printf("Total turnaround Time : %f\n", totalTAT);
            printf("Total Waiting Time : %f\n\n", totalWT/pN);
            
            printf("Average turnaround Time : %f\n", totalTAT/pN);
            printf("Average Waiting Time : %f\n", totalWT/pN);
        }

        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Option 3>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        else if(choice == '3'){   
            
            system("cls");
            printf("\n<<<<<<<<<<<<<<<Ending the Program>>>>>>>>>>>>>>\n\n");
            break;
        }
        else{       //<<<<<<<<<<<<<<<<Invalid Option>>>>>>>>>>>>>>>>>>

            system("cls");
            printf("Invalid Choice. Try Again.\n");
        }
        
    }

    return 0;
}