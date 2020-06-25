#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("Projet COVID19");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Projet Covid19"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,
      /* where the window ends up on the screen */
           800,                 /* The programs width */
           556,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}



LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HBITMAP  hBmp;


    switch (message)
    {

        case WM_COMMAND:
        switch(wParam)
        {
             case 1:
                ShellExecute(NULL,"open","projet.pdf",NULL,NULL,SW_SHOWNORMAL);
                break;

        case 2:
                ShowWindow(hwnd,SW_HIDE);
                ListePersonnesInfectees l;
                l=NULL;
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                AfficherPersonnesInfectees(l);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 3:
                ShowWindow(hwnd,SW_HIDE);
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                Ajouter(l);
                enregistrement(l,"personnesInfectees.txt","Maladies.txt");
                AfficherPersonnesInfectees(l);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 4:
                ShowWindow(hwnd,SW_HIDE);
                chaine cin;
                printf("Veuillez Insere CIN = ");
                scanf("%s", cin);
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                supprimer (l,cin);
                enregistrement(l,"personnesInfectees.txt","Maladies.txt");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 5:
                ShowWindow(hwnd,SW_HIDE);
                chaine CIN;
                chaine nmaladie;
                int annees;
                printf("Veuillez Insere  cin : ");
                scanf("%s",CIN);
                printf("Veuillez Insere nom maladie : ");
                scanf("%s",nmaladie);
                printf("Veuillez Insere  annee : ");
                scanf("%d",&annees);
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                AjouterMaladie (l,CIN,nmaladie,annees);
                enregistrement(l,"personnesInfectees.txt","Maladies.txt");
                AfficherPersonnesInfectees(l);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 6:
                ShowWindow(hwnd,SW_HIDE);
                 printf("Veuillez Insere cin = ");
                 scanf("%s",CIN);
                 l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                 modifierDeces(l,CIN);
                 enregistrement(l,"personnesInfectees.txt","Maladies.txt");
                 AfficherPersonnesInfectees(l);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;


        case 8:
                ShowWindow(hwnd,SW_HIDE);
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                chaine Nationalite;
                printf("Veuillez Insere la nationalite (En MAJUSCULE) : \t");
                scanf("%s",Nationalite);
                afficherParNationalite(l,Nationalite);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

                case 9:
                ShowWindow(hwnd,SW_HIDE);
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                date DateEnCours;
                printf("Veuillez Insere la date Sous Cette Forme JJ MM AAAA : \t");
                scanf("%d %d %d",&DateEnCours.jour,&DateEnCours.mois,&DateEnCours.annee);
                afficherPersonnesEnQuarantaine ( l,  DateEnCours);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

                 case 10:
                ShowWindow(hwnd,SW_HIDE);
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                afficherPersonnesDecedes(l);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

                 case 11:
                ShowWindow(hwnd,SW_HIDE);
                int age;
                char maladie;
                l=chargerPersonnes("personnesInfectees.txt","Maladies.txt");
                AfficherPersonnesARisque (l);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;


             case 13:
                ShellExecute(NULL,"open","projet.pdf",NULL,NULL,SW_SHOWNORMAL);
                break;


        case 14:
                if (MessageBox(hwnd,"Vous voulez quitter ?", "Oui", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;


        }
    case WM_CREATE :
        addmenus(hwnd);
            hBmp=LoadImage(NULL,"covidY.bmp",IMAGE_BITMAP,1200,900,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {
         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU hex1=CreateMenu();
    HMENU htab=CreateMenu();
    HMENU hex2=CreateMenu();
    HMENU hex22=CreateMenu();
    HMENU htp5=CreateMenu();
    HMENU htp11=CreateMenu();
    HMENU htp55=CreateMenu();
    HMENU hex15=CreateMenu();
    HMENU hex25=CreateMenu();
    HMENU hex225=CreateMenu();

    AppendMenu(hmenu,MF_STRING,1,"PDF");

    AppendMenu(hmenu,MF_STRING,2,"Consulter");

    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Manipuler");
    AppendMenu(htp1,MF_STRING,3,"1-Ajouter");
    AppendMenu(htp1,MF_STRING,4,"2-Supprimer");
    AppendMenu(htp1,MF_STRING,5,"3-Ajouter Maladie");
    AppendMenu(htp1,MF_STRING,6,"4-Modification Deces");



AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp11,"Chercher Personne ");

    AppendMenu(htp11,MF_STRING,8,"1-Par Nationalite");
    AppendMenu(htp11,MF_STRING,9,"2-En Quarantine");
    AppendMenu(htp11,MF_STRING,10,"3-Decedes");
    AppendMenu(htp11,MF_STRING,11,"4-A risque");

AppendMenu(hmenu,MF_STRING,14,"Exit");


    SetMenu(hwnd,hmenu);
}

