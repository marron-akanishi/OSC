#include "dxlib.h"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lp, int nC){
        int GraphHandle = -1;
        int FontHandle = -1;

        //������
        ChangeWindowMode(TRUE);
        SetMainWindowText("�摜�ƕ����̕\���e�X�g");
        SetGraphMode(800,600,32);
        if(DxLib_Init() == -1) return -1;
        SetDrawScreen(DX_SCREEN_BACK);

        //�e��t�@�C���̓ǂݍ���
        GraphHandle = LoadGraph("image.png");
        if(GraphHandle == -1) return -1;
        FontHandle = CreateFontToHandle("Migu 1P Regular",32,2,DX_FONTTYPE_ANTIALIASING_8X8);
        if(FontHandle == -1) return -1;
        
        //���C�����[�v
        while(ProcessMessage() == 0){
            ClearDrawScreen();
            DrawGraph(0,0,GraphHandle,TRUE);
            DrawStringToHandle(0,300,"Font Draw Test\n���{����\���\",GetColor(255,255,255),FontHandle);
            ScreenFlip();
        }

        //�I������
        DeleteGraph(GraphHandle);
        DeleteFontToHandle(FontHandle);
        DxLib_End();
        return 0;
} 