#include "Login.h"
#include <stdint.h>
#include <stdio.h>
#include "Service.h"



#define ID_LENGTH         5
#define PASSWORD_LENGTH   5
#define TRIALS_NUM        3




uint8_t LOGIN_u8CheckId[ID_LENGTH] = "1234" ;
uint8_t LOGIN_u8CheckPassword[PASSWORD_LENGTH] = "4321" ;






LOGIN_t LOGIN_IsValid(void)
{
    LOGIN_t LOCAL_Check = INVALID ;
    uint8_t LOCAL_u8Id[ID_LENGTH] = "1234" ;
    uint8_t LOCAL_u8Password[PASSWORD_LENGTH] = "4321" ;
    uint8_t ID = 1 ;
    uint8_t Password = 1 ;
    uint8_t LoginIterator  ;
    Print("\r\n Welcome to the alarm system .....\r\n");
    for(LoginIterator=0 ; LoginIterator < TRIALS_NUM ; LoginIterator++)
    {
        ID = 1 ;
    	Password = 1 ;
        uint8_t i  ;
        Print("\r\n Enter ID : ");
        Input(LOCAL_u8Id ,4);
        for ( i = 0; i < ID_LENGTH ; i++)
        {
            if(LOGIN_u8CheckId[i]!=LOCAL_u8Id[i])
            {

                ID = 0 ;

            }
        }
        Print("\r\n Enter Password : ");
        Input(LOCAL_u8Password ,4);
        Print("\r\n");

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

         /* Print("\r\n Welcome Eslam ...");  */
            break;
        }
         else if (ID==0 && Password ==1)
        {

         Print("\r\n Invalid Id ");

        }
        else if (ID==1 && Password ==0)
        {
            Print("\r\n Invalid Password");

        }
        else if (ID==0 && Password ==0)
        {
           Print("\r\n Invalid Id");
            Print("\r\n Invalid Password");

        }
        if(LoginIterator < TRIALS_NUM -1 )

        {

            Print("\r\n\r\n Try Again....\r\n");
        }

    }

    if (ID == 1 && Password == 1 )
    {
        LOCAL_Check = VALID ;
    }

    else
    {
    	
        Print("\r\n\r\n Invalid Login ");

       LOCAL_Check = INVALID ;

    }

    return  LOCAL_Check ;

}
