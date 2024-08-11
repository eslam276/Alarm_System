#include "Login.h"
#include <stdint.h>
#include <stdio.h>



#define ID_LENGTH         4
#define PASSWORD_LENGTH   4
#define TRIALS_NUM        3




uint8_t LOGIN_u8CheckId[ID_LENGTH] = {1,2,3,4} ;
uint8_t LOGIN_u8CheckPassword[PASSWORD_LENGTH] = {4,3,2,1} ;






LOGIN_t LOGIN_IsValid(void)
{

    LOGIN_t LOCAL_Check = INVALID ;


    uint8_t LOCAL_u8Id[ID_LENGTH] = {1,2,3,4} ;
    uint8_t LOCAL_u8Password[PASSWORD_LENGTH] = {4,3,2,1} ;
   


    uint8_t ID = 1 ;
    uint8_t Password = 1 ;

    uint8_t LoginIterator  ;

   



    printf("\nWelcome .....");
    

    for(LoginIterator=0 ; LoginIterator < TRIALS_NUM ; LoginIterator++)
    {

        ID = 1 ;
    	Password = 1 ;

        uint8_t i  ;



        printf("\nEnter ID : ");

        for ( i = 0; i < ID_LENGTH ; i++)
        {
            scanf("%d",&LOCAL_u8Id[i]);
        }

        

        for ( i = 0; i < ID_LENGTH ; i++)
        {
            if(LOGIN_u8CheckId[i]!=LOCAL_u8Id[i])
            {

                ID = 0 ;

            }
        }





        printf("\nEnter Password : ");

        for ( i = 0; i < PASSWORD_LENGTH ; i++)
        {
            scanf("%d",&LOCAL_u8Password[i]);
        }

        for ( i = 0; i < PASSWORD_LENGTH ; i++)
        {
            if(LOGIN_u8CheckPassword[i]!=LOCAL_u8Password[i])
            {

                Password = 0 ;

            }
        }



        if (ID == 1 && Password == 1 )
        {


          LOCAL_Check = VALID ;
          printf("\nWelcome Eslam");
         
             
            break;

        }


         else if (ID==0 && Password ==1)
        {

           

            printf("\nInvalid Id ");




        }


        else if (ID==1 && Password ==0)
        {

           

            printf("\nInvalid Password");




        }
        else if (ID==0 && Password ==0)
        {

            

           printf("\nInvalid Id");

         
            printf("\nInvalid Password");




        }


        if(LoginIterator < TRIALS_NUM -1 )

        {
        			

                  
            printf("\nTry Again..");
                   

        }

       




    }



    if (ID == 1 && Password == 1 )
    {
        LOCAL_Check = VALID ;
    }

    else
    {
    	
        printf("\nInvalid Login ");



       LOCAL_Check = INVALID ;

    }
    	









    return  LOCAL_Check ;

}