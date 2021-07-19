   /*  Data satructures  in C */ 

struct node {
	

	int data; 
	struct node *nextPtr; /* we a node of info then pointer to next. 2 members integer and pointer.*/  
}


/* next ptr memeber points to a struct odf type node. 
    A structure of the same type I wrote here. Thats why this is a self referencial structure. 
    */ 


/* Member nextPtr can be called link, or a tie. Because it links a 
structure of type struct node to another struct of the same type. 

/* Linked lists are a linear collection of self referential structures called nodes. 
   all connected by pointers = links. 
    This why we call them linked lists.  

  /* A linked list is accessed with a link pointer member that stays in each node. 
  

  /* never forget the link pointer member is ste to NULL, to show the end of the list

  /* Data is stored in the linked list dynamically 
  / * a node is created as necessary and each node can have any type od data including 
       another struct objects. 

   / * I can have node struct inside a node struct. or a for loop inside a struct that
        gets inside thwe struct node and finds another foor loop.... and so on.       

  /* stacks and queues are also linear data structures, but constrained versiions of linked lists. 

  /* but Trees are non linear data structures. 


 /* linked lists can be stored in arrays, but linked lists provid many advantages. 

 /* A linked list is great when the amount of data is unpredictable. So to store something like neuron activity data, linked lists  are dynamic as it is the brain. 

  /* Dynamic: The size or length can increase and decrease as necessary. 

  /* linked lists become only if the hardware has memory left to satisfy 
      dynamic memory allocation requests. Unlike, arrays become full once I first allocate memory. Arrays are not dynamic at all. 


   /* a tip: If I declare an array ot have more elements than the number of data items expected, this wil waste memory. 

   /* Linked lists will give me a better memory utilization to register synapses. 


  /* linked lists will maintain order by inserting each new element  in the proper point. Maybe I can control where exactly the proper point is, to insert new info. 

  /* There is a difference in access of Array vs linked lists. 
     an array is stored contiguously in the memory available, and this allows imediate access to any element. 
     
     the array has this advantage because the  memory address of any element can be calculated directly based on its position relative to the beginning of the array. 
     unfortunetly, Linked list does not give us imediate access.    
     But I don't believe we need it. Since we only want to store neuron synapses relative to time. 



  /* Using dynamic memory allocation,instead of arrays, for data structs that grow and shrink at execution time can save memory. But I gotta rememeber that 
  pointers take memory.
  and dynamuic memory allocation will have the overhead of function calls 

  /* this program provides 2 options: 1) insert a character in the alphabetic order.
    (Func insert ) 

    2) delete character from list (function delete)



*/


#include <stdio.h> 
#include <stdlib.h>


/* self-referential structures*/

struct listNode 
{
    char data;  // every list node will contain  brain synapse and              duration
    struct listNode *nextPtr // pointer to next node//
    
}/* end of the structure list node


 /* let's create another way to call on these nodes.*/
 
 
 typedef struct listNode ListNode; /* synonym for struc listNode*/ 
 typedef ListNode *ListNodePtr; /* synonym for listNode* */ 
 
 
   /* let's get some prototype  going*/ 
   
  void insert(ListNodePtr *sPtr, char value ); 
  /* this value will be a synapse. */ 
  
  char delete( ListNodePtr *sPtr, char value ); 
  
  int isEmpty( ListNodePtr sPtr); 
  
  void printList(ListNodePtr currentPtr );
  
  void instructions ( void ); 
  
  
  int main () 
  {
      
      
        ListNodePtr startPtr = NULL /* Initially there are no nodes */ 
        int choice;   /* users input. Means the brain synapse choice.*/ 

        char item;     /* char ended by user or synapse*/ 


  	    instructions();  /* dispaly the menu*/ 
         

        printf("what do you want to do?");
        scanf("%d" &choice); 

          /* I love writing and thinking about code */ 

          /* let's creat a loop which keeps on looping until the user chooses 3*/ 
          /* And use switch case here instead of if statements */ 


         while (choice != 3) {
         

            switch (choice)
            {

            	case 1: 
            	   printf("Enter a character: ") /* this will be a synapse */ 
            	   scanf("\n%c", &items);

            	 
            	insert ( &startPtr, item); /* insert item in list*/ 
            	printList( startPtr );
            	break;     
            
              

              /*  fundamentals of logic: 
              do you have right axioms,are they relevant? 
                 then are you making the right conclusions based on those axioms? */ 

               case 2: 

                  /* if list is not empty */ 

                  if (!isEmpty (startPtr) )
                  {
                  	printf("Enter Character to be deleted:   " );
                    scanf( "\n%c" , &item ); 
                        

                    /* if character is found, deleted right now */

                    if (delete (&startPtr,  item ) ){
                    	printf("%c deleted.\n" , item);
                    	printList( startPtr ); 
                    } /*end if */ 

                    else {
                    	printf ( "c% not found. \n\n");
                    }	
                  }
                    else {
                    	prinf("List is Empty. \n\n");
                    }  

                    break; 

                default: 
                     printf( "Invalid choice. \n\n" ); 
                     instructions(); 
                     break;     

                  }   

            } /* end switch */ 

           printf("?"); 
           scanf("%d" , &choice );       

         } /* end while loop */ 

         printf( " End of run. \n" ); 

         return 0; /* indicates successful termination */ 

     } /* end of main function */ 


      /* display program instruction to user: on screen or eyelid */ 

     void instructions ( void )
     {

     	printf("Enter your choice: \n");

               "   1 to insert element into the list. \n"
               "   2 to delete an element from the list \n"
               "   3 to end. \n" ); 


     	
	     }  

    
     void insert(ListNodePtr *sPtr, char value) 
     {  
     	ListNodePtr newPtr;     /*pointer to new node */ 
     	ListNodePtr previousPtr; /* Pointer to previous node in List */ 
     	ListNodePtr currentPtr;  /* pointer to current node in the list */ 

     	newPtr = malloc( sizeof( listNode) ); /* this line creates node */

     	if ( newPtr != NULL ) { /* is space available */ 
          newPtr -> data = value;  /* place the value in the node */ 
          newPtr -> nextPtr= NULL; /* this node stops the linking */ 

     	  previousPtr = NULL; 
     	  currentPtr = *sPtr; 

     	  /* loop to find the current location in the list */ 

     	  while ( currentPtr != NULL && value > currentPtr ->data )
     	  {
     	  	previousPtr = currentPtr;   /* keep looping through... */ 
     	  	currentPtr  = currentPtr ->nextPtr;  /*.. next node */ 

     	  }/* thats was an important while loop */ 

     	  /* insert a new node at the beggining of list */ 
     	  if ( previousPtr == NULL )
     	  {
            newPtr -> newPtr = *sPtr; 
            *sPtr = newPtr; 


     	  }  /* end if */ 
          else {
          	printf("%c not inserted. No memory available. \n");
          }  



         } /* end function insert */ 



         /* delete a list item */ 
         
        char delete ( listNodePtr *sPtr , char value )
        {

        	ListNodePtr previousPtr; /* pointer to  prev node in list */ 
        	ListNodePtr currentPtr;  /* pointer to the current node*/ 
        	ListNodePtr tempPtr;     /* temporary node pointer */ 

        	/* delete first node */ 

        	if ( value == ( *sPtr ) -> data )
        	{
        		tempPtr = *sPtr; /* hold unto node being removed */ 
        		*sPtr  = ( *sPtr ) ->nextPtr; /* de-thread the node */ 
        		free( temPtr );  /* free the de-thread node */ 
        		return value;
        	} /* end if */ 
        
         else {
         	previousPtr = *sPtr; 
         	curerntPtr = ( *sPtr )-> nextPtr; 


         	/* loop to find the correct location in the list */ 
         	while ( currentPtr != NULL && currentPtr -> data != value )
         	{
         		previousPtr =currentPtr; /* loop through until.. */ 
         		currentPtr = currentPtr->nextPtr; /*...next node */ 

         	} /* end while */ 

         	/* delete node at ccurrentPtr */ 
         	if  (currentPtr != NULL)
         	{
         		tempPtr= currentPtr; 
         		previousPtr->nextPtr = currentPtr ->nextPtr; 
         		free ( temPtr );
         		return value; 
         	}/* end if*/ 

         } /*else */ 

           return '\0';		
                 
        } /* end fucntion deledte * / 


        /*return 1 if the list is empty0 otherwise */ 

         int isEmpty ( ListNodePtr sPtr )
         { 
         	return sPtr == NULL; 

         } /* end Function isEmpty */ 

       /* print the  whole the list */ 
       

      void printList ( ListNodePtr currentPtr )
      {

      	/* if the list is empty */ 
      	if ( currentPtr == NULL)
      	{
      		printf(" List is empty. \n\n" );
      	}
    	else {
      		printf("The list is: \n" );
      	}

      /* while not the end of the list */ 
      while ( currentPtr != NULL )
      {
      	printf( "%c --> ", currentPtr->data );
      	currentPtr = currentPtr->nextPtr; 
      }	/*end While*/ 

      printf("NULL \n\n" ); 

      } /* end else */     





     }/* end function of to print the list*/    


  


