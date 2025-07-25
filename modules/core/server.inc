
#define MAX_SERVER_NAME 64 // ������������ ����� ����� �������
#define MAX_VERSION_SERVER 16 // ������������ ����� ������ �������
#define MAX_MAP_NAME 32 // ������������ ����� ����� �����
#define MAX_URL_LENGTH 64 // ������������ ����� URL ���-����� �������

stock Server_ModuleInit() {
    print("---------------------- [SERVER] MODULE STARTED ---------------------- ");
}


enum ServerData {
    SERVER_NAME[MAX_SERVER_NAME], // ��� �������
    SERVER_MODE[MAX_VERSION_SERVER], // ����� �������
    SERVER_MAP[MAX_MAP_NAME], // ������� ����� �������
    SERVER_WEBURL[MAX_URL_LENGTH], // URL ���-����� �������
    SERVER_WORLD_TIME_HOURS, // ���� � ������� ����
}
static ServerInfo[ServerData]; // ������ ��� �������� ������ �������


stock Server_SetHostName(const name[]) {
    new string[MAX_SERVER_NAME+7];
    format(string, sizeof string, "hostname %s", name);
    strmid(ServerInfo[SERVER_NAME], name, 0, sizeof(ServerInfo[SERVER_NAME]), sizeof(ServerInfo[SERVER_NAME]));
    SendRconCommand(string);
    printf("[SERVER] ��� ������� �����������: %s", ServerInfo[SERVER_NAME]);
}

stock Server_SetMode(const mode[]) {
    strmid(ServerInfo[SERVER_MODE], mode, 0, sizeof(ServerInfo[SERVER_MODE]), sizeof(ServerInfo[SERVER_MODE]));
    SetGameModeText(mode);
    printf("[SERVER] ����� ������� ����������: %s", ServerInfo[SERVER_MODE]);
}

stock Server_SetMap(const map[]) {
    new string[MAX_MAP_NAME+7];
    format(string, sizeof string, "mapname %s", map);
    strmid(ServerInfo[SERVER_MAP], map, 0, sizeof(ServerInfo[SERVER_MAP]), sizeof(ServerInfo[SERVER_MAP]));
    SendRconCommand(string);
    printf("[SERVER] ����� ������� �����������: %s", ServerInfo[SERVER_MAP]);
}

stock Server_SetLanguage(const language[]) {
    new string[32];
    format(string, sizeof string, "language %s", language);
    SendRconCommand(string);
    printf("[SERVER] ���� ������� ����������: %s", language);
}

