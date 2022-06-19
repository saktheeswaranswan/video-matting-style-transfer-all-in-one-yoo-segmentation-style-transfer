//
// Created by DefTruth on 2022/6/19.
//

#ifndef LITE_AI_TOOLKIT_ORT_CV_FACE_HAIR_SEG_H
#define LITE_AI_TOOLKIT_ORT_CV_FACE_HAIR_SEG_H

#include "lite/ort/core/ort_core.h"

namespace ortcv
{
  class LITE_EXPORTS FaceHairSeg : public BasicOrtHandler
  {
  public:
    explicit FaceHairSeg(const std::string &_onnx_path, unsigned int _num_threads = 1) :
        BasicOrtHandler(_onnx_path, _num_threads)
    {};

    ~FaceHairSeg() override = default;

  private:
    Ort::Value transform(const cv::Mat &mat) override;

    void generate_mask(std::vector<Ort::Value> &output_tensors,
                       const cv::Mat &mat, types::FaceHairSegContent &content,
                       bool remove_noise = false);

  public:
    void detect(const cv::Mat &mat, types::FaceHairSegContent &content,
                bool remove_noise = false);
  };
}

#endif //LITE_AI_TOOLKIT_ORT_CV_FACE_HAIR_SEG_H
