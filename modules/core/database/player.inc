forward Mysql_SearchPlayer(playerid);
public Mysql_SearchPlayer(playerid)
{
    new rows;
    if(rows) {
        SendClientMessage(playerid, -1, "Игрок найден в базе данных.");
    } else {
        SendClientMessage(playerid, -1, "Игрок не найден в базе данных.");
    }
    return 1;
}