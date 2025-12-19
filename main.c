#include<stdio.h>
#include<ctype.h>   //For isdigit()
int main(){

    printf("\n");
    printf("====================================================================================================\n");
    printf("----------ROUND ROBIN ALGORITHM----------\n");
    printf("CS-407 : Operating Systems\n");
    printf("====================================================================================================\n");
    printf("\n");
    
    char choice;
    do{
        while(1){
            
            printf("====================\n");
            printf("Please Select an Option:-\n");
            printf("1. Without Arrival Time.\n");
            printf("2. With Arrival Time.\n");
            printf("Input(1-2) : ");
            scanf(" %c", &choice);   //The blank space before the %c is there for a reason. When scanf takes an input char from the user, there is also a \n buffer because of which the invalid_____ message prints twice.
            
            if(!isdigit(choice)){
                
                printf("Invalid Input. Please Try Again\n");
            }
            else{

                break;
            }
        }
        if(choice == '1'){     //<<<<<<<<<<<<<<<<Option 1>>>>>>>>>>>>>>>>>>
            
            printf("===========ROUND ROBIN ALGORITHM WITHOUT ARRIVAL TIME=========\n");

            //---------------Number of Processes---------------

            printf("===========Number of Processes=========\n");
            int pN,maxProcesses = 20;
            while(1){

                printf("Enter the Number of Processes(Max : %d) : ", maxProcesses);
                scanf("%d", &pN);

                if(pN > maxProcesses){       //To set process limit
                    
                    printf("Maximum Process limit is %d.Try Again.\n", maxProcesses);
                }
                else if(pN < 0){

                    printf("Number of processes must be in positive.\n");
                }
                else{

                    break;
                }
            }

            int burstTime[pN], remainingTime[pN], turnAroundTime[pN] , waitingTime[pN];

            //---------------Burst Time---------------

            printf("===========Burst Time=========\n");
            for(int i=0; i<pN; i++){

                printf("----------Process # %d----------\n", i+1);
                printf("Enter the burst time  of P%d: ", i+1);
                scanf("%d", &burstTime[i]);
                remainingTime[i] = burstTime[i];
            }
    
            //---------------Quantum Time---------------

            printf("===========Quantum Time=========\n");
            int quantumT;
            printf("Enter the Quantum Time : ");
            scanf("%d", &quantumT);
            
            //---------------Table---------------

            printf("===========Table=========\n");
            printf("Process \t BurstTime\n");
            for(int i=0; i<pN; i++){
                
                printf("P%d \t\t %d\n", i+1, burstTime[i]);
                turnAroundTime[i] = 0;
            }

            //---------------Gant Chart---------------

            printf("===========Gant Chart=========\n");
            int processIndex = -1, currentTime = 0 , execTime = 0;  
            int completedProcess = 0;

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

            printf("Average turnaround Time : %f\n", totalTAT/pN);
            printf("Average Waiting Time : %f\n", totalWT/pN);
        }
        else if(choice == '2'){    //<<<<<<<<<<<<<<<<Option 2>>>>>>>>>>>>>>>>>>
            
        }
        else{       //<<<<<<<<<<<<<<<<Invalid Option>>>>>>>>>>>>>>>>>>

            printf("Invalid Choice. Try Again.\n");
        }
        
    }while(choice!=1 && choice!=2);

    return 0;
}