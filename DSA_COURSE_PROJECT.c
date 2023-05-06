#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#define MAX 50

#define INFINITE 9999


//Structure name: lid
//Use: To store user details
//Number of attributes: 16

typedef struct lid
{

	//unique for each user used for searching
	int id;

	// for logging in
	char username[30];

	// security purpose
	char password[100];

	//First name of the user
	char f_name[30];

	//Last name of the user
	char l_name[30];

	//Age of the user
	int age;

	//Education of the user
	char qualification[100];

	//Institution where the user is studying or had studied
	char institution[100];

	//Interests of the user
	char interest[100];

	//Contact information of the user
	long long int mobile_number;

	//Personal email id of the user
	char email_id[50];

	//Location of the user
	char location[100];

	//Top skill of the user
	char topskill[100];

	//Industry knowledge of the user
	char industryk[100];

	//Tools the user are proficient in
	char tools[100];

	//Others skill of the user
	char others[100];



}
L;
L data[100];

int global = 0;
//  count of users


int n[MAX][MAX];
// Network array which is based on dijkstra's algorithm


int flag = 0;
// flag here works like a switch for login


//Function name: load_from_file()
//Description: Reads
// user information from file
//Input type: NULL
//Return type: Void

void minimum_distance(int G[MAX][MAX], int n, int startnode)
{
    //Adjacency Matrix
	int cost[MAX][MAX];

	//Array to maintain distance from a vertex
	int distance[MAX];

	//Array to maintain the vertex
	int pred[MAX];

	//Array to maintain vertex that have been visited
	int visited[MAX];

	int count, mindistance, nextnode;
	int  i, j;

	for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
        {
			if (G[i][j] == 0)
            {
				cost[i][j] = INFINITE;
			}
			else
            {
				cost[i][j] = G[i][j];

				//weight is assigned as 1 automatically.

            }
        }

    }

	//initialize pred[],distance[] and visited[]
	for (i = 0; i < n; i++)
    {
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count < n - 1) {
		mindistance = INFINITE;

		//nextnode gives the node at minimum distance
		for (i = 0; i < n; i++)
        {
			if (distance[i] < mindistance && !visited[i])
            {
				mindistance = distance[i];
				nextnode = i;
			}
        }

		//check if a better path exists through nextnode
		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
        {
			if (!visited[i])
            {
				if (mindistance + cost[nextnode][i] < distance[i])
                {
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
            }
        }
		count++;
	}


	//print the path and distance of each node
	for (i = 0; i < n; i++)
    {
		if (distance[i] < 9999 && distance[i] != 0)
        {
			if (i != startnode)
			{

				//printf("Link is =",data[i].f_name);

			}
			printf("\n");
			j = i;
			printf("%s ", data[i].f_name);

			do
            {
				j = pred[j];
				printf("<-%s", data[j].f_name);


				//printf("<-%d",j);
			} while (j != startnode);


		}
	}
	printf("\n\n\n");
}


//Function name: load_from_file()
//Description: Reads user information from file
//Input type: NULL
//Return type: Void

void load_from_file()
{
	global = 0;
	FILE * fp;

	//Open the file in read mode

	fp = fopen("C:/Users/owner/Desktop/k.txt", "r");

	// Check if the file was successfully opened

	if (fp == NULL)
    {
		printf("File Not found\n");
		return;
	}

	// Until the end of the file, read all the file data

	while (!feof(fp))
    {
		//printf("\nHI\n %d \n",global);

		fscanf(fp, "%s %s %s %s %d %s %s %s %lld %s %d %s %s %s %s %s", data[global].username,data[global].password,data[global].f_name,data[global].l_name,
          &data[global].age,data[global].qualification,data[global].institution,data[global].interest,&data[global].mobile_number,data[global].email_id,
          &data[global].id, data[global].location,data[global].topskill,data[global].industryk,data[global].tools,data[global].others);


	/*	printf("%s %s %d %s %s %s %lld %s %d %s %s %s %s %s\n", data[global].f_name, data[global].l_name, data[global].age, data[global].qualification,
			data[global].institution, data[global].interest,
			data[global].mobile_number,data[global].email_id, data[global].id,data[global].location,data[global].topskill,data[global].industryk,data[global].tools,data[global].others);
		printf("%s %s\n", data[global].username, data[global].password);
		*/



		global++;
	}

	global = global - 1;

	//printf("HI %d\n",global);

	fclose(fp);
}


//Function name: initialize_network()
//Description: Initializing the user network
//Input type: NULL
//Return type: Void

void initialize_network()
{
    printf("Global is = %d\n", global);
	int i, j;
	FILE * fl;

	//Open the file in read mode

	fl = fopen("C:/Users/owner/Desktop/j.txt", "r");

	// Check if the file was successfully opened

	if (fl == NULL)
    {
		printf("File Not found\n");
		return;
	}

	// Until the end of the file, read all the file data

	// Until the end of the file, read all the file data

	while (!feof(fl))
    {


		for (i = 0; i < global; i++)
        {
			for (j = 0; j < global; j++)
            {

				{
					fscanf(fl, "%d", & n[i][j]);

				}

			}


		}
	}


	fclose(fl);
}


//Function name: welcome()
//Description: For the console
//Input type: NULL
//Return type: Void

void welcome()
{

	//For the console

	int i;
	for (i = 0; i < 80; i++)
		printf("*");

	printf("\n\n\t\t\t\tLINKEDiN\n\n\n");

	for (i = 0; i < 80; i++)
    {
		printf("*");
    }

	printf("\n\n");

}


//Function name: create_account()
//Description: To create new user account
//Input type: NULL
//Return type: Void

void create_account()
{
	int i;
	char p[100];
	FILE * fp;
	L temp;

	//Getting the new user information
	printf("Enter your username\n");
	scanf("%s", temp.username);

	//Setting up the password
	printf("Enter your password\n");
	scanf("%s", temp.password);

	//Confirming the entered password
	printf("Enter the password again\n");
	scanf("%s", p);

	if (strcmp(p, temp.password) == 0)
    {

		printf("\nPassword Confirmed!\n");

		//Once the password is confirmed, new user inputs his information

        //First name of new user

		printf("Enter first name\n");
		scanf("%s", temp.f_name);

        //Last name of new user

		printf("Enter last name\n");
		scanf("%s", temp.l_name);

        //Age of new user

		printf("Enter your age\n");
		scanf("%d", & temp.age);

        //Qualification of new user

		printf("Enter your qualifications\n");
		scanf("%s", temp.qualification);

        //Institution where the new user is studying or had studied

		printf("Enter your institution name\n");
		scanf("%s", temp.institution);

        //Interest of new user

		printf("Enter your interest\n");
		scanf("%s", temp.interest);

        //Contact information of new user

		printf("Enter mobile number\n");
		scanf("%lld", & temp.mobile_number);

        //Personal email ID of new user

		printf("Enter your email\n");
		scanf("%s", temp.email_id);

        //Location of new user

		printf("Enter your location\n");
		scanf("%s", temp.location);

        //Top skill of new user

		printf("Enter your top skill\n");
		scanf("%s", temp.topskill);

        //Industry knowledge of new user

		printf("Enter field in which you have industry knowledge\n");
		scanf("%s", temp.industryk);

        //Tools the new user is proficient in

		printf("Enter tools your proficient in\n");
		scanf("%s", temp.tools);

        //Other skills of new user

		printf("Enter your other skills\n");
		scanf("%s", temp.others);


	}

	  //Open the file in append mode

     fp = fopen("C:/Users/owner/Desktop/k.txt", "a");

     //Check if the file is empty

     if(fp == NULL)
     {
         printf("ACCOUNT NOT CREATED \n");
         return;
     }
     else
    {

	temp.id = global ;

	printf("%d %s %s %s %s %d %s %s %s %lld %s %s %s %s %s %s\n", temp.id, temp.username, temp.password, temp.f_name, temp.l_name, temp.age, temp.qualification,
		temp.institution, temp.interest, temp.mobile_number, temp.email_id, temp.location, temp.topskill, temp.industryk, temp.tools, temp.others);


	fprintf(fp, "%s %s %s %s %d %s %s %s %lld %s %d %s %s %s %s %s\n", temp.username, temp.password, temp.f_name, temp.l_name, temp.age, temp.qualification,
		temp.institution, temp.interest, temp.mobile_number, temp.email_id, temp.id, temp.location, temp.topskill,
		temp.industryk, temp.tools, temp.others);

    }

	fclose(fp);
	printf("\nAccount created SUCCESSFULLY!\n");
	return;

}


//Function name: login()
//Description: For the user who already have an account
//Input type: NULL
//Return type: User ID (Integer)

int login()
{
	char username1[30];
	int i;
	char password1[30];

	printf("ENTER THE USERNAME\n");
	fflush(stdout);

	scanf("%s", username1);

	for (i = 0; i < global; i++)
    {
		if (strcmp(username1, data[i].username) == 0)
		{
			printf("ENTER PASSWORD\n");
			scanf("%s", password1);
			if (strcmp(password1, data[i].password) == 0)
			{
				flag = 1;
				printf("LOGGED IN\n");

				return data[i].id;

				// return the id of user
			}
		}
	}


	printf("USERNAME OR PASWORD NO MATCH \n");


	printf("Do You want to try again or create a an account\n Press 1 to create an account press 2 to try again\n");

	int j;
	scanf("%d", & j);

	switch (j)
	{
		case 1:
			create_account();
			break;
		case 2:
			login();
			break;

	}

}


//Function name: load_data()
//Description: To view details of user
//Input type: User ID (Integer)
//Return type: Void

void load_data(int x)
{
	int i;
	for (i = 0; i < global - 1; i++)
    {
        // match of id

		if (data[i].id == x)
		{
			printf("\n\nName: %s %s \nAge:%d\nProfession: %s\nCollege: %s\nInterest: %s\nPh no: %lld\nEmail:  %s\nId: %d\nLocation: %s\n \
                    Top Skill: %s\nIndustry Knowledge: %s\nTools: %s\nOthers: %s\n",
				data[i].f_name, data[i].l_name, data[i].age, data[i].qualification, data[i].institution, data[i].interest,
				data[i].mobile_number, data[i].email_id,data[i].id, data[i].location, data[i].topskill, data[i].industryk,
				data[i].tools, data[i].others);

		}
	}
}


//Function name: merge()
//Description: To merge user's inactive accounts
//Input type: NULL
//Return type: Void

void merge()
{
	char u[100], p[100];

	printf("Enter your previous username\n");
	scanf("%s", u);
	printf("Enter your password\n");
	scanf("%s", p);

	printf("\nTo merge your inactive accounts buy our new PREMIUM for just Rs.999!!!\n");

}


//Function name: view()
//Description: To view the skills and endorsements of the user
//Input type: NULL
//Return type: Void

void view()
{
	int n;
	printf("\nEnter your ID\n");
	scanf("%d", & n);

	printf("%s %s %s %s\n", data[n - 1].topskill, data[n - 1].industryk, data[n - 1].tools, data[n - 1].others);
}


//Function name: spage()
//Description: For creating showcase pages
//Input type: NULL
//Return type: Void

void spage()
{
	printf("\n\n");

	printf("To create showcase pages buy our Premium just for Rs.999!!!\n");

	printf("\n");

}


//Function name: add_friend(int x)
//Description: To add another user as a friend
//Input type: User ID (Integer)
//Return type: Void

void add_friend(int x)
{

	printf("the id is %d\n", x);

	int i;
	int z;

	//Shows all available users

	for (i = 0; i < global; i++)
    {
		if (i != x)
		{
			printf("%s %d\n", data[i].f_name, data[i].id);
		}
	}

    //User can follow any other account as per his/her wish

	printf("Enter the id you want to follow\n");
	scanf("%d", & z);
	n[x][z] = 1;
	n[z][x] = 1;

}


//Function name: user_manual()
//Description: Basic Guide for Getting Started on LinkedIn
//Input type: NULL
//Return type: Void

void user_manual()
{

    //Basic guide to users

	printf("What is LinkedIn?\n");
	printf("• Professional networking site \n");
	printf("• Can think of this as a more detailed online resume\n \
            • Way for you to establish professional contacts, keep in touch, search for jobs, join groups to get updates on topics that interest you, request \
              informational interviews, and be found and contacted by recruiters Using the site is free for all of the basic features\n Creating a Profile \n \
            • Go to www.linkedin.com \n \
            • You will need an email address to register \n \
            • Quickest way to start is by importing your resume; it will auto-fill \n \
            • Title: a few words about how you want to identify yourself (i.e. job seeker, warehouse \n \
              professional) \n \
            • Summary: key things you want an employer to know about you (professional!) \n \
            • Experience: use your resume as a cheat sheet, can have same bullet points, reverse \n \
              chronology \n \
            • Education \n \
            • Add a picture (optional) \n \
              “Linking” to People (adding people to your network) \n \
            • Use search function (or Advanced), find who you want, and click “Add to network” \n \
            • Indicate how you know them (if other, have to enter email address) \n \
            • Once you are Linked to someone, you can view their connections and send them \n \
              messages \n \
            Joining Groups \n \
            • Go to the “Groups” tab at the top \n \
            • Can search for groups or go to “Groups You May Like” \n \
            • Once you join groups, you can receive discussion updates and/or relevant job \n \
              postings by email \n \
              Finding Jobs \n \
            • Go to “Jobs” tab at the top of the page \n \
            • Can apply online and your profile is included with your application \n \
            • Can “follow” companies, which can give you updates about new jobs\n \
              Recommendations\n \
            • Go to the “Profile” tab at the top of the page and click on “Recommendations” \n \
            • Will show list of your past jobs; click on “ask to be endorsed”\n \
            • Select from your connections (you must already be connected to the people you ask \n \
               to endorse you) \n \
            For More Information \n \
            • LinkedIn New User Guide: http:learn.linkedin.com/new-users/ ");



    printf("\n\n");




}


//Function name: new_initialize(int m)
//Description: Has all the functions
//Input type:
//Return type: Integer

void new_initialize(int m)
{

    printf("hi %d\n",global);

    int i,j;

	for (i = 0; i < global; i++)
    {
		for (j = 0; j < global; j++)
		{
			if (i == global - 1 && j == global - 1)
			{
				n[i][j] = INFINITE;
			}
            else if (i == j)
            {
				n[i][j] = 0;
			}
		}
	}

	/*for (int q = 0; q <= global; q++)
	 {
					for (int w = 0; w < global; w++)
                    {
						printf("%d ", n[q][w]);
					}

					printf("\n");

				}*/


}


//Function name: search()
//Description: To search other users
//Input type: NULL
//Return type: Integer

void search()
{
	int i;
	char x[100];

	printf("\nEnter the complete username of the user to be searched\n");
	gets(x);

	for (i = 0; i < global; i++)
    {
		// match of username

		if (strcmp(data[i].username, x) == 0)
		{
			printf("\n\nName: %s %s \nAge:%d\nProfession: %s\nCollege: %s\nInterest: %s\n\n", data[i].f_name, data[i].l_name, data[i].age,
                     data[i].qualification, data[i].institution, data[i].interest);
		}
	}
}


//Function name: store_network()
//Description: To show user network
//Input type: NULL
//Return type: Void

void store_network()
{
    int i,j;

	FILE * f;

	//Open the file in write mode

	f = fopen("C:/Users/owner/Desktop/j.txt", "w");

	// Check if the file was successfully opened

	if (f == NULL)
    {
		printf("File Not found\n");
		return;
	}


	// Until the end of the file, read all the file data

	for (i = 0; i < global; i++)
    {
		for (j = 0; j < global; j++)
		{
			fprintf(f, "%d ", n[i][j]);
		}

		fprintf(f,"\n");
	}

	//printf("HI %d\n",global);

	fclose(f);
}


//Function name: main()
//Description: Has all the functions
//Input type: NULL
//Return type: Integer

int main()
{
	int i;

	int ch;

	// heading of the console

	welcome();

	int z;

	// extracting data

	load_from_file();
	initialize_network();

	/*for (int q = 0; q < global; q++) {
		for (int w = 0; w < global; w++) {
			printf("%d ", n[q][w]);
		}

		printf("\n");
	}*/

	//Operations that can be performed

	while(1)
    {

		printf("\n1.User Manual\n2.Login\n3.Create account\n");
        printf("4.View your skills and endorsements\n5.Merge your inactive accounts\n6.Create Showcase Page\n");
		printf("7.log out \n8.Follow\n9.Network\n10.Search\n11.Exit\n");


		printf("enter your choice \n");
		scanf("%d", & z);


        //User Manual to use LinkedIn

		if (z == 1)
        {
			printf("\nCheck the Manual Below\n");
			user_manual();

			//Login
		}


		//Login

		if (z == 2)
        {
			if (flag == 0)
			{


				i = login();
				load_data(i);


			}
			else
            {
				printf("First log out from this account \n");
			}


		}


		//Create Account

		if (z == 3)
        {
			//printf("Check\n");
            printf("DONT USE SPACE \n");
			create_account();
			load_from_file();

			//printf("Hi   %d\n",global);

			new_initialize(global);
		}


		//View your skills and endorsements

		if (z == 4)
        {
			printf("\nKindly login before viewing skills and endorsements :)\n");
			i = login();
			printf("Check\n");
			view();
		}


		//Merge your inactive accounts

		if (z == 5)
        {
			printf("\nKindly login before merging your inactive accounts :)\n");
			i = login();
			merge();
		}


		//Create showcase page

		if (z == 6)
        {
			printf("\nKindly login before creating showcase pages :)\n");
			i = login();
			spage();
		}


        //Log out

		if (z == 7)
        {
			printf("Logged out\n");
			flag = 0;
		}


		//Follow other accounts

		if (z == 8)
        {
			if (flag == 1)
			{
				printf("Friend recommendations are \n");
				add_friend(i);

				//printf("ddd %d\n", global);
				/*for (int q = 0; q <= global; q++) {
					for (int w = 0; w < global; w++) {
						printf("%d ", n[q][w]);
					}
					printf("\n");
				}
				*/

				//  display_connection(i);
			}
			else
            {
				printf("First log in\n");
				login();
			}

		}


		//User network

		if (z == 9)
        {
			if (flag == 1)
			{
				printf("Your network is \n");
				minimum_distance(n, global, i);
			}
			else
            {
                printf("First log in\n");
                login();
            }
		}


		//Search for other users

		if (z == 10)
        {

			if (flag == 1)
			{
				search();
			}

            else
            {
				printf("First log in\n");

				login();
			}

		}


        //View your social network

		if (z == 11)
        {
			store_network();

			// when we exit the network should be stored so that it can be used again when we again run the program as we may have followed a new person


		}


		//Exit from LinkedIn

        if(z == 12)
        {
            //Confirm before exiting

            printf("\nSure you want to exit?\n");
            printf("\n1.YES          2.NO\n");
            scanf("%d",&ch);

            if(ch == 1)
            {
                exit(0);
            }

            else;

        }

		welcome();

	}

	return 0;

}
