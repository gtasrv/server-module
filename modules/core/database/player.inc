forward Mysql_SearchPlayer(playerid);
public Mysql_SearchPlayer(playerid)
{
    new rows;
    if(rows) {
        SendClientMessage(playerid, -1, "����� ������ � ���� ������.");
    } else {
        SendClientMessage(playerid, -1, "����� �� ������ � ���� ������.");
    }
    return 1;
}