#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
 
 
 int main(){

	    int President_N1 = 0 , President_N2 = 0 ,President_N3 = 0  ,Voters_N ,min = 0 ,max=0 ,max1=1;
	    int Vote_R1,Vote_R2,Vote_R3, Vote_R4, index, v1=0, R1=0, v=0; 
		int Per=15, min_PN=3, min_Vo=3;
		float Percentage;
	    char President1[100][50], President2[100][50], President3[100][50], Voters[100][50];
	    int VoteR1[100], VoteR2[100], VoteR3[100];

	     
	    
	    	printf("\t\t\t################### Welcome to Voting 2021 ###################\n");
	    	printf("\t\t\t#############################hiiiiiii#########hiii 2########################\n");
     
	 	//demande du nombre de president et de electeur: President_N1  Voters_N
	 	do{
     		printf("\nPlease Enter The Number of Presidents: ");
	     	scanf("%d",&President_N1);
		 }while(President_N1 < min_PN); //nim 3
		do{
			printf("Please Enter The Number of Voters: ");
    	 	scanf("%d",&Voters_N);
		 }while(Voters_N < min_Vo);	//nim 3
		 
		 
		//ramplissage du table president: President1[i]
	    for(int i = 0; i < President_N1; i++)
	    	{
		        printf("\tEnter The Name of President  %d: ",i);  
		        scanf("%s", President1[i]);				
	    	}
 
	    //ramplissage du table electeur : Voters[i]
	    for(int i=0; i<Voters_N ;i++)
	     	{
	         printf("Enter The CIN of The Voter %d: ",i+1);
	         scanf("%s",Voters[i]);							
	   		}

     	
	    //affichage des Presidents : President1[i]
	    for(int i=0 ; i<President_N1 ; i++)
	        {
	         printf("\t\t## for President '%s' Select Number --> %d \t##\n",President1[i],i);
	        }
	    		printf("\t\tPlease select The Name of President\n");
	    		   
				     
	    //initialisation de table du votes: VoteR1
	    for (int i = 0 ; i < President_N1;i++)
	    {
	    	VoteR1[i] = 0;
		}
	

		//remplissage de la table du votes: VoteR1																				:§
		for(int i = 0 ; i < Voters_N ; i++)
		{
			printf("Hi '%s' Please Select a President By His Number: ",Voters[i]);  //by number
			scanf("%d",&Vote_R1);
			VoteR1[Vote_R1]++;									
		}
		 
		//test du Percentage moin de 15% : Per=15
		//les Presidents qui ont plus que 15% seront copy au table presidents2: Presidents1[]-->Presidents2[] 
		for(int i = 0 ; i < President_N1 ; i++)
		{
			Percentage =(float)VoteR1[i]/(float)Voters_N*100;		///nombre des votes sur nombre des electeurs fois 100
			printf("\t%d Voted for '%s'\n",VoteR1[i],President1[i]);	//§§	
			printf("\t\tThePresident '%s' Has %.2f % \n",President1[i],Percentage); 
			
			//les Presidents qui ont plus que 15% seront copy au table presidents2: Presidents1[]-->Presidents2[] 
			if(Percentage>Per)		//Per=15%
			{
				strcpy(President2[President_N2], President1[i]);	 //President2[] new table for president >15
					President_N2++;		//=0								
			}	
		}

do{
		printf("\n\n\t\t\t#################### ROUND 2 OF THE ELECTION ####################\n");
		
	//affichage des president qui ont un pourssantage de Vote plus que 15
	    for(int i = 0 ; i < President_N2 ; i++)         //number of perisident from round 1: President1[]
     	{
         printf("\t\tThe Name of President %d is --> %s \n",i,President2[i]);
    	}
    
    //initialisation de la table VoteR2
	    for (int i = 0 ; i < President_N2;i++)
	    {
	    	VoteR2[i] =0;
		}
		
	//remlissage de la table du vote de ROUND 2	VoteR2 avec aide de Vote_R2
		for(int i = 0 ; i < Voters_N ; i++)
		{
			printf("'%s' Please Select a President By His Number:  ",Voters[i]);
			scanf("%d",&Vote_R2);
			VoteR2[Vote_R2]++;										
		}
		// si tous les president a le meme nbr de vote
	//	int v=0;
		for(int i = 0 ; i < President_N2-1 ; i++)
		{
		  if(VoteR2[i] != VoteR2[i+1]){
		  	v=1;
		  }	
		}
		if(v==0){
			printf("Please Enter The President Name Again\n");		//do it again to move to round 3
				
		}
	//	else{
		
	// affichage de nombre des votes pour chaque President       §§
		for(int i = 0 ; i < President_N2 ; i++)
			printf("\t%d Voted for '%s'\n",VoteR2[i],President2[i]);
			
	//le minimum 
	//les Presidents qui ont les plus grand seront copy au table President3[]
		min = VoteR2[0];					//Number nim des votes
		for(int i=1; i<President_N2; i++) 
		{
			if( min > VoteR2[i])
			{
				min = VoteR2[i];
			}		
		}
		//les Presidents qui ont plus grand seront copy au table President3[]
		for(int i = 0 ; i < President_N2 ; i++)
		{
			if(min < VoteR2[i])    
			{
				strcpy(President3[President_N3],President2[i]);		//President3[] new table for president > min
				President_N3++;											
			}
		}    
		//}
		}while(v!=1);
		
	do{	
		printf("\t\t\t#################### ROUND 3 OF THE ELECTION ####################\n");
	  
	    for(int i = 0 ; i < President_N3 ; i++)
     	{
        printf("\t\tThe Name of President %d is --> %s \n",i,President3[i]);
   		}
    
	  	//initialisation de la table VoteR3
	    for (int i = 0 ; i < President_N3;i++)
	    {
	    	VoteR3[i] = 0;
		}
			
		//remlissage de la table du VoteR2
		for(int i = 0 ; i < Voters_N ; i++)
		{
			printf("%s Please Select a President By His Number:  ",Voters[i]);
			scanf("%d",&Vote_R3);
			VoteR3[Vote_R3]++;										
		}
		// si tous les president a le meme nbr de vote
		for(int i = 0 ; i < President_N3-1 ; i++)
		{
			if(VoteR3[i]!=VoteR3[i+1]){
		  	v1=1;
		    }	
		}
			if(v1==0){				//to do it again
			printf("enter the president name again\n");		
		}
		
		// affichage de nombre des votes pour chaque President  §§
		for(int i = 0 ; i < President_N3 ; i++){
		
			printf("\t%d Voted for '%s'\n",VoteR3[i],President3[i]);
		}    

		//test du vote max
		//le President qui a plus des votes is the winner
		 max = VoteR3[0];
		for(int i=1; i<President_N3; i++) 
		{
			if( max < VoteR3[i])
			{
				max = VoteR3[i];
				index=i;
			}			
		}
		}while(v1!=1);
		printf("\t\t### the winner is '%s' ###",President3[index]);


return 0;

 }
