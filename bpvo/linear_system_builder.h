#ifndef LINEAR_SYSTEM_BUILDER_H
#define LINEAR_SYSTEM_BUILDER_H

#include <bpvo/template_data.h>
#include <bpvo/types.h>

namespace bpvo {

class LinearSystemBuilder
{
 public:
  typedef typename TemplateData::JacobianVector JacobianVector;
  typedef typename TemplateData::PixelVector    ResidualsVector;
  typedef typename TemplateData::Jacobian       Jacobian;
  typedef std::vector<uint8_t> ValidVector;

  typedef Eigen::Matrix<float, 6, 1> Gradient;
  typedef Eigen::Matrix<float, 6, 6> Hessian;

 public:
  LinearSystemBuilder(LossFunctionType = LossFunctionType::kHuber);

  /**
   * \return the norm of the weighted residuals
   */
  float run(const JacobianVector& J, const ResidualsVector& R,
            const ValidVector& valid, Hessian&, Gradient& b);

  float run(const ResidualsVector& R, const ValidVector& valid);

 private:
  LossFunctionType _loss_func;
  ResidualsVector _tmp_buffer;
}; // LinearSystemBuilder

}; // bpvo

#endif // LINEAR_SYSTEM_BUILDER_H
