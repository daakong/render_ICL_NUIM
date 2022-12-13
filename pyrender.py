import os
import random

import numpy as np
import transforms3d

from test import val_test_func


# val_list = ["val00", "val01", "val02",
#             "val10", "val11", "val12",
#             "val20", "val21", "val22",
#             "val30", "val31", "val32"]


# val00 = str(val00)
# val01 = str(val01)
# val02 = str(val02)
# val10 = str(val10)
# val11 = str(val11)
# val12 = str(val12)
# val20 = str(val20)
# val21 = str(val21)
# val22 = str(val22)
# val30 = str(val30)
# val31 = str(val31)
# val32 = str(val32)

def generate_traj(total_steps):
    traj_ = []
    val00 = 0.998739
    val01 = 0.00725321
    val02 = -0.0496855
    val10 = 0.00725319
    val11 = 0.958294
    val12 = 0.285692
    val20 = 0.0496855
    val21 = -0.285692
    val22 = 0.957033
    val30 = 90
    val31 = 465
    val32 = -292
    mat = np.array([[val00, val01, val02],
                    [val10, val11, val12],
                    [val20, val21, val22]])
    euler = transforms3d.euler.mat2euler(mat)
    x = val30
    y = val31
    z = val32
    euler_x = euler[0]
    euler_y = euler[1]
    euler_z = euler[2]
    for s in range(20):
        # 20 steps move forward
        z = z + 3
        pos = np.array([x, y, z, euler_x, euler_y, euler_z])
        traj_.append(pos)

    for s in range(30):
        # rotate 30 steps
        euler_x = euler_y + 0.05
        pos = np.array([x, y, z, euler_x, euler_y, euler_z])
        traj_.append(pos)

    for s in range(20):
        # 20 steps move forward
        z = z + 2
        x = x + 1
        pos = np.array([x, y, z, euler_x, euler_y, euler_z])
        traj_.append(pos)

    return traj_


def get_right_cam_pos(pos: np.array, baseline_x=10, baseline_y=0, baseline_z=0):
    val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32 = decode_traj_pos(pos)
    t = np.array([[val00, val01, val02, val30],
                  [val10, val11, val12, val31],
                  [val20, val21, val22, val32],
                  [0, 0, 0, 1]], dtype=float)
    right_cam = np.matmul(t, np.array([baseline_x, baseline_y, baseline_z, 1]).T)
    return right_cam


def stereo_render():
    print("Starting stereo rendering.")
    scene_path = os.getcwd()
    scene_path = str(scene_path + "/icl-office")
    traj = []
    # traj.append(np.array([x, y, z, euler[0], euler[1], euler[2]])
    traj = generate_traj(100)

    cnt = 0
    for i_pos in traj:
        val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32 = decode_traj_pos(i_pos)
        right_cam = get_right_cam_pos(i_pos)
        left_cam = np.array([val30, val31, val32])
        cam_list = ["left", "right"]
        for cam in cam_list:
            # render left camera first
            val30 = left_cam[0]
            val31 = left_cam[1]
            val32 = left_cam[2]
            val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32 = str_vals(
                val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32)
            left_out_name = str("stereo_out/" + "left" + "/" + str(cnt).rjust(5, "0"))
            render(scene_path,
                   val00, val01, val02, val10, val11, val12, val20, val21, val22,
                   val30, val31, val32, left_out_name)
            right_out_name = str("stereo_out/" + "right" + "/" + str(cnt).rjust(5, "0"))
            render(scene_path,
                   val00, val01, val02, val10, val11, val12, val20, val21, val22,
                   str(right_cam[0]), str(right_cam[1]), str(right_cam[2]), right_out_name)
        cnt = cnt + 1
    print("Finished " + str(len(traj)) + "pairs of stereo rendering.")


def rotate_test():
    path = os.getcwd()
    path = str(path + "/icl-office")

    val00 = 0.998739
    val01 = 0.00725321
    val02 = -0.0496855
    val10 = 0.00725319
    val11 = 0.958294
    val12 = 0.285692
    val20 = 0.0496855
    val21 = -0.285692
    val22 = 0.957033
    val30 = 90
    val31 = 465
    val32 = -292
    mat = np.array([[val00, val01, val02],
                    [val10, val11, val12],
                    [val20, val21, val22]])
    euler = transforms3d.euler.mat2euler(mat)

    list = ["y", "z"]
    for axis in list:
        for i in range(10):
            cnt = str(i)
            euler_x = euler[0]
            euler_y = euler[1] + (0.1 * i - 0.4) * (axis == "y")
            euler_z = euler[2] + (0.1 * i - 0.4) * (axis == "z")
            mat_i = transforms3d.euler.euler2mat(euler_x, euler_y, euler_z)
            val00 = str(mat_i[0, 0])
            val01 = str(mat_i[0, 1])
            val02 = str(mat_i[0, 2])
            val10 = str(mat_i[1, 0])
            val11 = str(mat_i[1, 1])
            val12 = str(mat_i[1, 2])
            val20 = str(mat_i[2, 0])
            val21 = str(mat_i[2, 1])
            val22 = str(mat_i[2, 2])
            val30 = str(val30)
            val31 = str(val31)
            val32 = str(val32)

            out_name = str("val_test/rotate_" + axis + "_" + str(i))
            render(path,
                   val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32, out_name)

    print("Rotate test done.")


def render(path,
           val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32,
           output_name):
    os.chdir(path)

    pass1 = str(" /usr/local/bin/povray +Ioffice.pov +O" + output_name + ".png +W640 +H480" +
                "+wt64 +RFradiosity_first_pass/scene_radiosity_000.txt +RFO -d " +
                "+L/usr/local/bin/povray/include +LLightsysIV +Lmaps +HIfirst_pass_settings.inc  +FN16 " +
                " Declare=val00=" + val00 + "  Declare=val01=" + val01 + "  Declare=val02=" + val02 +
                " Declare=val10=" + val10 + "  Declare=val11=" + val11 + "  Declare=val12=" + val12 +
                " Declare=val20=" + val20 + "  Declare=val21=" + val21 + "  Declare=val22=" + val22 +
                " Declare=val30=" + val30 + "  Declare=val31=" + val31 + "  Declare=val32=" + val32
                )
    os.system(pass1)

    pass2 = str(
        "/usr/local/bin/povray +Ioffice.pov +O" + output_name + ".png +W640 +H480" +
        "wt64 +RFradiosity_first_pass/scene_radiosity_000.txt +RFI -d" +
        "L/usr/local/bin/povray/include +LLightsysIV +Lmaps +HIsecond_pass_settings.inc  +FN16 " +
        " Declare=val00=" + val00 + "  Declare=val01=" + val01 + "  Declare=val02=" + val02 +
        " Declare=val10=" + val10 + "  Declare=val11=" + val11 + "  Declare=val12=" + val12 +
        " Declare=val20=" + val20 + "  Declare=val21=" + val21 + "  Declare=val22=" + val22 +
        " Declare=val30=" + val30 + "  Declare=val31=" + val31 + "  Declare=val32=" + val32
    )
    os.system(pass2)
    print("A rendering work finished.")


def decode_traj_pos(pos: np.array, out_type="vals"):
    out_list = []
    mat_i = transforms3d.euler.euler2mat(pos[3], pos[4], pos[5])
    val30 = str(pos[0])
    val31 = str(pos[1])
    val32 = str(pos[2])
    val00 = str(mat_i[0, 0])
    val01 = str(mat_i[0, 1])
    val02 = str(mat_i[0, 2])
    val10 = str(mat_i[1, 0])
    val11 = str(mat_i[1, 1])
    val12 = str(mat_i[1, 2])
    val20 = str(mat_i[2, 0])
    val21 = str(mat_i[2, 1])
    val22 = str(mat_i[2, 2])
    if out_type == "vals":
        return val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32
    elif out_type == "list":
        out_list = [val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32]
    return out_list


def str_vals(val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32):
    val00 = str(val00)
    val01 = str(val01)
    val02 = str(val02)
    val10 = str(val10)
    val11 = str(val11)
    val12 = str(val12)
    val20 = str(val20)
    val21 = str(val21)
    val22 = str(val22)
    val30 = str(val30)
    val31 = str(val31)
    val32 = str(val32)
    return val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32


if __name__ == '__main__':
    stereo_render()
    print("Main done.")
