#include "pSubstract.h"
#include "..\pObjectList.hpp"

using namespace YSE::PATCHER;

#define className pSubstract

CONSTRUCT_DSP() {

  // default data
  leftIn = nullptr;
  rightIn = nullptr;
  rightFloatIn = 1.f;

  // in 0: audio buffer
  ADD_IN_0;
  REG_BUFFER_IN(pSubstract::SetLeftBuffer);

  // in 1: multiplier (float or audio)
  ADD_IN_1;
  REG_BUFFER_IN(pSubstract::SetRightBuffer);
  REG_FLOAT_IN(pSubstract::SetRightFloat);

  // out 0: audio output
  ADD_OUT_BUFFER;

  ADD_PARAM(rightFloatIn);
}

BUFFER_IN(pSubstract::SetLeftBuffer) {
  leftIn = buffer;
}

BUFFER_IN(pSubstract::SetRightBuffer) {
  rightIn = buffer;
}

FLOAT_IN(pSubstract::SetRightFloat) {
  rightFloatIn = value;
}

RESET() // {
  leftIn = rightIn = nullptr;
}

CALC() {
  output = *leftIn;

  if (rightIn == nullptr) {
    output -= rightFloatIn;
  }
  else {
    output -= *rightIn;
  }

  outputs[0].SendBuffer(&output);
}