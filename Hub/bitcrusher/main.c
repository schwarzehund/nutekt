//AUDIOTEC CODE 

#include "usermodfx.h"
#include "float_math.h"

static float rate, lastSampleL, lastSampleR;
static int32_t count;

//初期化処理
void MODFX_INIT(uint32_t platform, uint32_t api)
{
  lastSampleL = 0.f;
  lastSampleR = 0.f;
  count = 0;
}

void MODFX_PROCESS(const float *main_xn, float *main_yn,
                   const float *sub_xn, float *sub_yn,
                   uint32_t frames)
{

  //エフェクト処理のループ
  for (uint32_t i = 0; i < frames; i++)
  {

    //LとRの音を用意する
    const float inL = main_xn[i * 2];
    const float inR = main_xn[i * 2 + 1];

    //大きくなるほどサンプルが粗くなる
    uint32_t skip = rate * 64;

    //countが0の時だけlastSampleを更新する
    if (count == 0)
    {
      lastSampleL = inL;
      lastSampleR = inR;
    }

    //lastSampleの音を継続する
    main_yn[i * 2] = lastSampleL;
    main_yn[i * 2 + 1] = lastSampleR;
    count++;

    //skipを超えたらcountを0にリセット
    if (count > (int)skip)
      count = 0;
  }
}

void MODFX_PARAM(uint8_t index, int32_t value)
{
  //固定小数点q31フォーマットをfloatに変換
  const float valf = q31_to_f32(value);
  switch (index)
  {

  //timeツマミを回した時にrateに値を代入
  case k_user_modfx_param_time:
    rate = valf;
    break;
  default:
    break;
  }
}
