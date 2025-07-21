stock Player_ModuleInit() {
    print("Модуль игрока инициализирован");
}


enum PlayerInfo {
    PlayerName[MAX_PLAYER_NAME],
    PlayerScore,
    PlayerHealth,
    PlayerArmor
}
static PlayerData[MAX_PLAYERS][PlayerInfo];

stock Player_Connected(playerid) {
    GetPlayerName(playerid, PlayerData[playerid][PlayerName], MAX_PLAYER_NAME);
    printf("%s", PlayerData[playerid][PlayerName]);
    Database_SearchPlayer(playerid);
}

stock Player_GetPlayerID(userid) {
    return PlayerData[userid][PlayerID];
}  
stock Player_GetPlayerName(playerid, output[MAX_PLAYER_NAME]) {
    format(output, sizeof(output), "%s", PlayerData[playerid][PlayerName]);
    return 1;
}