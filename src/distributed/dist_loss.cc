//------------------------------------------------------------------------------
// Copyright (c) 2016 by contributors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

/*
Author: Chao Ma (mctt90@gmail.com)
This file is the implementation of the base Loss class.
*/

#include "src/distributed/dist_loss.h"
#include "src/distributed/dist_cross_entropy_loss.h"

namespace xLearn {

//------------------------------------------------------------------------------
// Class register
//------------------------------------------------------------------------------
CLASS_REGISTER_IMPLEMENT_REGISTRY(xLearn_dist_loss_registry, DistLoss);
REGISTER_DIST_LOSS("dist-cross-entropy", DistCrossEntropyLoss);

// Predict in one thread
void pred_thread(const DMatrix* matrix,
                 Model* model,
                 std::vector<real_t>* pred,
                 DistScore* dist_score_func_,
                 bool is_norm,
                 size_t start_idx,
                 size_t end_idx) {
  /*
  CHECK_GE(end_idx, start_idx);
  for (size_t i = start_idx; i < end_idx; ++i) {
    SparseRow* row = matrix->row[i];
    real_t norm = is_norm ? matrix->norm[i] : 1.0;
    (*pred)[i] = dist_score_func_->CalcScore(row, *model, norm);
  }
  */
}

// Predict in multi-thread
void DistLoss::Predict(const DMatrix* matrix,
                   Model& model,
                   std::vector<real_t>& pred) {
  /*
  CHECK_NOTNULL(matrix);
  CHECK_NE(pred.empty(), true);
  CHECK_EQ(pred.size(), matrix->row_length);
  index_t row_len = matrix->row_length;
  // Predict in multi-thread
  for (int i = 0; i < threadNumber_; ++i) {
    size_t start_idx = getStart(row_len, threadNumber_, i);
    size_t end_idx = getEnd(row_len, threadNumber_, i);
    pool_->enqueue(std::bind(pred_thread,
                             matrix,
                             &model,
                             &pred,
                             dist_score_func_,
                             norm_,
                             start_idx,
                             end_idx));
  }
  // Wait all of the threads finish their job
  pool_->Sync(threadNumber_);
  */
}

}  // namespace xLearn
