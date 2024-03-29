/*
 * Copyright 2020 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "vvas_xdpupriv.hpp"

#include <vitis/ai/medicaldetection.hpp>
#include <vitis/ai/nnpp/medicaldetection.hpp>

using namespace std;
using namespace cv;

class vvas_xmedicaldet:public vvas_xdpumodel
{

  int log_level = 0;
    std::unique_ptr < vitis::ai::MedicalDetection > model;
  char (*label_str)[MAX_NAME_LENGTH];

public:

  vvas_xmedicaldet (vvas_xkpriv * kpriv, const std::string & model_name,
      bool need_preprocess);

  virtual int run (vvas_xkpriv * kpriv, std::vector<cv::Mat>& images,
      GstInferencePrediction **predictions);

  virtual int requiredwidth (void);
  virtual int requiredheight (void);
  virtual int supportedbatchsz (void);
  virtual int close (void);

  virtual ~vvas_xmedicaldet ();
};
