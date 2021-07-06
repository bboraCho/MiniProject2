#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

void insert();
void update();
void delete();
void selectAll();
void selectOne();
void searchList();
int main(int argc, char **argv)
{
   //pi@raspberrypi:~/cPro $ sudo apt install libsqlite3-dev
   //pi@raspberrypi:~/cPro $ sudo apt install sqlite3
   printf("Hello sqlite3...\n");
   
   //insert();
   
   //update();
   
   //delete();
   
   selectAll();
   printf("===============\n");
   //selectOne();
   
   searchList();
   
   return 0;
}

void insert(){
   printf("insert()....\n");
   
   int result_open = 0;
   sqlite3 *db;
   result_open = sqlite3_open("test23.db", &db);
   //gcc -Wall -o "test23sqlite3" "test23sqlite3.c" -lsqlite3
   
   
   printf("result_open:%d...\n",result_open);
   if(!result_open){
      printf("sqlite3_open successfully! \n");
   }
   
   sqlite3_stmt *stmt = NULL;
   
   //1.table create
   const char *sql_create_table = "create table if not exists test(num integer primary key autoincrement,name text,age integer,wdate default CURRENT_TIMESTAMP);";
   
   int result_create_table = sqlite3_prepare_v2(db,sql_create_table,-1,&stmt,NULL);//SQLITE_OK:0
   printf("%d,%d\n",result_create_table,SQLITE_OK);
   if(result_create_table==SQLITE_OK){
      int step = sqlite3_step(stmt);//SQLITE_DONE:101
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("create table successfully! \n");
         printf("sqlite3 test23.db \".tables\"\n");
         system("sqlite3 test23.db \".tables\"\n");
      }
   }
   ///////////////////////////////////////////////
   printf("============================\n");
   //2.table insert
   const char *sql_insert = "insert into test(name,age) values(?,?);";
   int result_insert = sqlite3_prepare_v2(db,sql_insert,-1,&stmt,NULL);
   printf("%d,%d\n",result_insert,SQLITE_OK);
   if(result_insert == SQLITE_OK){
      sqlite3_bind_text(stmt,1,"han77",-1,SQLITE_TRANSIENT);
      sqlite3_bind_int(stmt,2,75);
      
      int step = sqlite3_step(stmt);
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("insert successfully! \n");
         printf("sqlite3 test23.db \"select * from test\"\n");
         system("sqlite3 test23.db \"select * from test\"\n");
      }
   }
   sqlite3_finalize(stmt);
   sqlite3_close(db);
   
}//end insert()

void update(){
   printf("update()....\n");
   int result_open = 0;
   sqlite3 *db;
   result_open = sqlite3_open("test23.db", &db);
   //gcc -Wall -o "test23sqlite3" "test23sqlite3.c" -lsqlite3
   
   
   printf("result_open:%d...\n",result_open);
   if(!result_open){
      printf("sqlite3_open successfully! \n");
   }
   
   sqlite3_stmt *stmt = NULL;
   
   //1.table create
   const char *sql_create_table = "create table if not exists test(num integer primary key autoincrement,name text,age integer,wdate default CURRENT_TIMESTAMP);";
   
   int result_create_table = sqlite3_prepare_v2(db,sql_create_table,-1,&stmt,NULL);//SQLITE_OK:0
   printf("%d,%d\n",result_create_table,SQLITE_OK);
   if(result_create_table==SQLITE_OK){
      int step = sqlite3_step(stmt);//SQLITE_DONE:101
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("create table successfully! \n");
         printf("sqlite3 test23.db \".tables\"\n");
         //system("sqlite3 test23.db \".tables\"\n");
      }
   }
   const char *sql_update = "update test set name=?, age=? where num=?;";
   int result_update = sqlite3_prepare_v2(db,sql_update,-1,&stmt,NULL);
   printf("%d,%d\n",result_update,SQLITE_OK);
   if(result_update == SQLITE_OK){
      sqlite3_bind_text(stmt,1,"aaaa",-1,SQLITE_TRANSIENT);
      sqlite3_bind_int(stmt,2,44);
      sqlite3_bind_int(stmt,3,3);
      
      int step = sqlite3_step(stmt);
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("update successfully! \n");
         printf("sqlite3 test23.db \"select * from test\"\n");
         system("sqlite3 test23.db \"select * from test\"\n");
      }
   }
      
   sqlite3_finalize(stmt);
   sqlite3_close(db);
   
}//end update()


void delete(){
   printf("delete()....\n");
   
   int result_open = 0;
   sqlite3 *db;
   result_open = sqlite3_open("test23.db", &db);
   //gcc -Wall -o "test23sqlite3" "test23sqlite3.c" -lsqlite3
   
   
   printf("result_open:%d...\n",result_open);
   if(!result_open){
      printf("sqlite3_open successfully! \n");
   }
   
   sqlite3_stmt *stmt = NULL;
   
   //1.table create
   const char *sql_create_table = "create table if not exists test(num integer primary key autoincrement,name text,age integer,wdate default CURRENT_TIMESTAMP);";
   
   int result_create_table = sqlite3_prepare_v2(db,sql_create_table,-1,&stmt,NULL);//SQLITE_OK:0
   printf("%d,%d\n",result_create_table,SQLITE_OK);
   if(result_create_table==SQLITE_OK){
      int step = sqlite3_step(stmt);//SQLITE_DONE:101
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("create table successfully! \n");
         printf("sqlite3 test23.db \".tables\"\n");
         //system("sqlite3 test23.db \".tables\"\n");
      }
   }
   ///////////////////////////////////////////////
   
   //4.table delete : num=2
   const char *sql_delete = "delete from test where num=?;";
   int result_delete = sqlite3_prepare_v2(db,sql_delete,-1,&stmt,NULL);
   printf("%d,%d\n",result_delete,SQLITE_OK);
   if(result_delete == SQLITE_OK){
      sqlite3_bind_int(stmt,1,2);
      
      int step = sqlite3_step(stmt);
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("delete successfully! \n");
         printf("sqlite3 test23.db \"select * from test\"\n");
         system("sqlite3 test23.db \"select * from test\"\n");
      }
   }
      
   sqlite3_finalize(stmt);
   sqlite3_close(db);
}//end delete()



void selectAll(){
   printf("selectAll()....\n");
   
   int result_open = 0;
   sqlite3 *db;
   result_open = sqlite3_open("test23.db", &db);
   //gcc -Wall -o "test23sqlite3" "test23sqlite3.c" -lsqlite3
   
   
   printf("result_open:%d...\n",result_open);
   if(!result_open){
      printf("sqlite3_open successfully! \n");
   }
   
   sqlite3_stmt *stmt = NULL;
   
   //1.table create
   const char *sql_create_table = "create table if not exists test(num integer primary key autoincrement,name text,age integer,wdate default CURRENT_TIMESTAMP);";
   
   int result_create_table = sqlite3_prepare_v2(db,sql_create_table,-1,&stmt,NULL);//SQLITE_OK:0
   printf("%d,%d\n",result_create_table,SQLITE_OK);
   if(result_create_table==SQLITE_OK){
      int step = sqlite3_step(stmt);//SQLITE_DONE:101
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("create table successfully! \n");
         printf("sqlite3 test23.db \".tables\"\n");
         system("sqlite3 test23.db \".tables\"\n");
      }
   }

   //4.table seleceAll
   const char *sql_seleceAll = "select num,name,age,wdate from test;";
   int result_seleceAll = sqlite3_prepare_v2(db,sql_seleceAll,-1,&stmt,NULL);
   printf("%d,%d\n",result_seleceAll,SQLITE_OK);
   if(result_seleceAll == SQLITE_OK){
      while(sqlite3_step(stmt) == SQLITE_ROW){
         printf("%d ",(int)sqlite3_column_int(stmt,0));
         printf("%s ",(char*)sqlite3_column_text(stmt,1));
         printf("%d ",(int)sqlite3_column_int(stmt,2));
         printf("%s \n",(char*)sqlite3_column_text(stmt,3));
      }
      
   }

   sqlite3_finalize(stmt);
   sqlite3_close(db);
}//end selectAll()




void selectOne(){
   printf("selectOne()....\n");
   int result_open = 0;
   sqlite3 *db;
   result_open = sqlite3_open("test23.db", &db);
   //gcc -Wall -o "test23sqlite3" "test23sqlite3.c" -lsqlite3
   
   
   printf("result_open:%d...\n",result_open);
   if(!result_open){
      printf("sqlite3_open successfully! \n");
   }
   
   sqlite3_stmt *stmt = NULL;
   
   //1.table create
   const char *sql_create_table = "create table if not exists test(num integer primary key autoincrement,name text,age integer,wdate default CURRENT_TIMESTAMP);";
   
   int result_create_table = sqlite3_prepare_v2(db,sql_create_table,-1,&stmt,NULL);//SQLITE_OK:0
   printf("%d,%d\n",result_create_table,SQLITE_OK);
   if(result_create_table==SQLITE_OK){
      int step = sqlite3_step(stmt);//SQLITE_DONE:101
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("create table successfully! \n");
         printf("sqlite3 test23.db \".tables\"\n");
         //system("sqlite3 test23.db \".tables\"\n");
      }
   }
   
   //5.table seleceOne : num=4
   const char *sql_seleceOne = "select num,name,age,wdate from test where num=?;";
   int result_seleceOne = sqlite3_prepare_v2(db,sql_seleceOne,-1,&stmt,NULL);
   printf("%d,%d\n",result_seleceOne,SQLITE_OK);
   if(result_seleceOne == SQLITE_OK){
      sqlite3_bind_int(stmt,1,4);
      while(sqlite3_step(stmt) == SQLITE_ROW){
         printf("%d ",(int)sqlite3_column_int(stmt,0));
         printf("%s ",(char*)sqlite3_column_text(stmt,1));
         printf("%d ",(int)sqlite3_column_int(stmt,2));
         printf("%s \n",(char*)sqlite3_column_text(stmt,3));
      }
      
   }

   sqlite3_finalize(stmt);
   sqlite3_close(db);
}//end selectOne()



void searchList(){
   printf("searchList()....\n");
   int result_open = 0;
   sqlite3 *db;
   result_open = sqlite3_open("test23.db", &db);
   //gcc -Wall -o "test23sqlite3" "test23sqlite3.c" -lsqlite3
   
   
   printf("result_open:%d...\n",result_open);
   if(!result_open){
      printf("sqlite3_open successfully! \n");
   }
   
   sqlite3_stmt *stmt = NULL;
   
   //1.table create
   const char *sql_create_table = "create table if not exists test(num integer primary key autoincrement,name text,age integer,wdate default CURRENT_TIMESTAMP);";
   
   int result_create_table = sqlite3_prepare_v2(db,sql_create_table,-1,&stmt,NULL);//SQLITE_OK:0
   printf("%d,%d\n",result_create_table,SQLITE_OK);
   if(result_create_table==SQLITE_OK){
      int step = sqlite3_step(stmt);//SQLITE_DONE:101
      printf("%d,%d\n",step,SQLITE_DONE);
      if(step==SQLITE_DONE){
         printf("create table successfully! \n");
         //printf("sqlite3 test23.db \".tables\"\n");
         //system("sqlite3 test23.db \".tables\"\n");
      }
   }
   
   //6.table searchList : searchKey,searchWord
   char *sql_searchList = "";
   char *sql_searchList_name = "select num,name,age,wdate from test where name like ?;";
   char *sql_searchList_age = "select num,name,age,wdate from test where age like ?;";
   
   char front_percent[20] = {"%"};
   char back_percent[20] = {"%"};
   
   //char *searchKey = "name";
   //char searchWord[10] = "an";
   char *searchKey = "age";
   char searchWord[10] = "5";
   //char searchWord[10];
   //scanf("%s",searchWord);
   
   
   //printf("front_percent:%s\n",front_percent);
   strcat(front_percent,searchWord);
   //printf("front_percent+searchWord:%s\n",front_percent);
   strcat(front_percent,back_percent);
   //printf("front_percent+back_percent:%s\n",front_percent);
   strcpy(searchWord,front_percent);
   //printf("searchWord:%s\n",searchWord);
   //printf("%d\n",strcmp(searchKey,"name")==0);
   if(strcmp(searchKey,"name")==0){
      //printf("%s\n",sql_searchList_name);
      sql_searchList = sql_searchList_name;
   }else if(strcmp(searchKey,"age")==0){
      //printf("%s\n",sql_searchList_age);
      sql_searchList = sql_searchList_age;
   }
   
   printf("%s\n",sql_searchList);
   int result_searchList = sqlite3_prepare_v2(db,sql_searchList,-1,&stmt,NULL);
   printf("%d,%d\n",result_searchList,SQLITE_OK);
   if(result_searchList == SQLITE_OK){
      sqlite3_bind_text(stmt,1,searchWord,-1,SQLITE_TRANSIENT);
      while(sqlite3_step(stmt) == SQLITE_ROW){
         printf("%d ",(int)sqlite3_column_int(stmt,0));
         printf("%s ",(char*)sqlite3_column_text(stmt,1));
         printf("%d ",(int)sqlite3_column_int(stmt,2));
         printf("%s \n",(char*)sqlite3_column_text(stmt,3));
      }
      
   }
   
   sqlite3_finalize(stmt);
   sqlite3_close(db);
}//end searchList()
