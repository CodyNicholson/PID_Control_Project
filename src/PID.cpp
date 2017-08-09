#include <cmath>
#include <iostream>
#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = d_error = i_error = 0.0;

    // Twiddle params
    use_twiddle = false;
    dp = {0.1*Kp,0.1*Kd,0.1*Ki};
    step = 1;
    param_index = 2;
    settle_steps = 100;
    eval_steps = 2000;
    total_error = 0;
    best_error = std::numeric_limits<double>::max();
    try_add = false;
    try_subtract = false;
}

void PID::UpdateError(double cte) {
    if (step == 1) {
        // Get correct initial d_error
        p_error = cte;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

    // Update total error if past number settle steps
    if (step % (settle_steps + eval_steps) > settle_steps){
        total_error += pow(cte,2);
    }

    // Should we use twiddle?
    if (use_twiddle && step % (settle_steps + eval_steps) == 0){
        cout << "step: " << step << endl;
        cout << "total error: " << total_error << endl;
        cout << "best error: " << best_error << endl;
        if (total_error < best_error) {
            cout << "improvement!" << endl;
            best_error = total_error;
            if (step !=  settle_steps + eval_steps) {
                dp[param_index] *= 1.1;
            }
            param_index = (param_index + 1) % 3;
            try_add = try_subtract = false;
        }
        if (!try_add && !try_subtract) {
            AddToDpAtIndex(param_index, dp[param_index]);
            try_add = true;
        }
        else if (try_add && !try_subtract) {
            AddToDpAtIndex(param_index, -2 * dp[param_index]);
            try_subtract = true;
        }
        else {
            AddToDpAtIndex(param_index, dp[param_index]);
            dp[param_index] *= 0.9;
            param_index = (param_index + 1) % 3;
            try_add = try_subtract = false;
        }
        total_error = 0;
        cout << "new parameters" << endl;
        cout << "P: " << Kp << ", I: " << Ki << ", D: " << Kd << endl;
    }
    step++;
}

double PID::TotalError() {
    return 0.0;  // ?
}

void PID::AddToDpAtIndex(int index, double amount) {
    if (index == 0) {
        Kp += amount;
    }
    else if (index == 1) {
        Kd += amount;
    }
    else if (index == 2) {
        Ki += amount;
    }
    else {
        std::cout << "AddToDpAtIndex: index out of bounds";
    }
}
