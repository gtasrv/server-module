stock Database_ModuleInit() {
    print("----------------------  [DATABASE] MODULE STARTED ---------------------- ");
    Database_ConnectToBase();



    // mysql_query(dbHandle, "CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, username VARCHAR(255) NOT NULL, password VARCHAR(255) NOT NULL)", false);
}
static MySQL:dbHandle;
static stock Database_ConnectToBase() {
    dbHandle = mysql_connect("localhost", "root", "root", "module");
    if (mysql_errno(dbHandle) != 0) {
        printf("[DATABASE] Ошибка подключения к базе данных - #%d", mysql_errno(dbHandle));
        return 0;
    }
    return print("[DATABASE] Подключение к базе данных успешно установлено");
}

stock Database_SearchPlayer(playerid) {
    new query[41+MAX_PLAYER_NAME-2], name[MAX_PLAYER_NAME];
    // GetPlayerName(playerid, name, MAX_PLAYER_NAME);
    Player_GetPlayerName(playerid, name);
    mysql_format(dbHandle, query, sizeof(query), "SELECT * FROM users WHERE username = '%s'", 
       name
    );
    mysql_tquery(dbHandle, query, "Mysql_SearchPlayer", "i", playerid);
}



#include "../modules/core/database/player.inc"