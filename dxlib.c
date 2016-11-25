#include "dxlib.h"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lp, int nC){
        int GraphHandle = -1;
        int FontHandle = -1;

        //初期化
        ChangeWindowMode(TRUE);
        SetMainWindowText("画像と文字の表示テスト");
        SetGraphMode(800,600,32);
        if(DxLib_Init() == -1) return -1;
        SetDrawScreen(DX_SCREEN_BACK);

        //各種ファイルの読み込み
        GraphHandle = LoadGraph("image.png");
        if(GraphHandle == -1) return -1;
        FontHandle = CreateFontToHandle("Migu 1P Regular",32,2,DX_FONTTYPE_ANTIALIASING_8X8);
        if(FontHandle == -1) return -1;
        
        //メインループ
        while(ProcessMessage() == 0){
            ClearDrawScreen();
            DrawGraph(0,0,GraphHandle,TRUE);
            DrawStringToHandle(0,300,"Font Draw Test\n日本語も表示可能",GetColor(255,255,255),FontHandle);
            ScreenFlip();
        }

        //終了処理
        DeleteGraph(GraphHandle);
        DeleteFontToHandle(FontHandle);
        DxLib_End();
        return 0;
} 