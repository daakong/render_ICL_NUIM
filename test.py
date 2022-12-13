import  os
import  numpy as np
import transforms3d

def val_test_func():
    path = os.getcwd()
    path = str(path + "/icl-office")
    os.chdir(path)
    # os.system("./render_all.sh")
    # val_list = ["val00", "val01", "val02",
    #             "val10", "val11", "val12",
    #             "val20", "val21", "val22",
    #             "val30", "val31", "val32"]
    val_list = ["val00", "val01", "val02",
                "val10", "val11", "val12",
                "val20", "val21", "val22"]

    for i_val in val_list:
        for i in range(10):
            cnt = str(i)
            # location < val30, val31, val32 >
            # direction < val20, val21, val22 >
            # up < val10, val11, val12 >
            # // right < val00, val01, val02 > *1.33

            val00 = str(0.998739 + 0.1 * i * (i_val == "val10"))
            val01 = str(0.00725321 + 0.1 * i * (i_val == "val10"))
            val02 = str(-0.0496855 + 0.1 * i * (i_val == "val10"))
            val10 = str(0.00725319 + 0.1 * i * (i_val == "val10"))
            val11 = str(0.958294 + 0.1 * i * (i_val == "val11"))
            val12 = str(0.285692 + 0.1 * i * (i_val == "val12"))
            val20 = str(0.0496855 + 0.05 * i * (i_val == "val20"))
            val21 = str(-0.285692 + 0.05 * i * (i_val == "val21"))
            val22 = str(0.957033 + 0.05 * i * (i_val == "val22"))
            val30 = str(90 + 10 * i * (i_val == "val30"))
            val31 = str(465 + 10 * i * (i_val == "val31"))
            val32 = str(-292 + 10 * i * (i_val == "val32"))


            com1 = str(" /usr/local/bin/povray +Ioffice.pov +Oval_test/" + i_val + "_" + cnt + ".png +W640 +H480" +
                       "+wt64 +RFradiosity_first_pass/scene_radiosity_000.txt +RFO -d " +
                       "+L/usr/local/bin/povray/include +LLightsysIV +Lmaps +HIfirst_pass_settings.inc  +FN16 " +
                       " Declare=val00=" + val00 + "  Declare=val01=" + val01 + "  Declare=val02=" + val02 +
                       " Declare=val10=" + val10 + "  Declare=val11=" + val11 + "  Declare=val12=" + val12 +
                       " Declare=val20=" + val20 + "  Declare=val21=" + val21 + "  Declare=val22=" + val22 +
                       " Declare=val30=" + val30 + "  Declare=val31=" + val31 + "  Declare=val32=" + val32
                       )
            os.system(com1)

            com2 = str(
                "/usr/local/bin/povray +Ioffice.pov +Oval_test/" + i_val + "_" + cnt + ".png +W640 +H480" +
                "wt64 +RFradiosity_first_pass/scene_radiosity_000.txt +RFI -d" +
                "L/usr/local/bin/povray/include +LLightsysIV +Lmaps +HIsecond_pass_settings.inc  +FN16 " +
                " Declare=val00=" + val00 + "  Declare=val01=" + val01 + "  Declare=val02=" + val02 +
                " Declare=val10=" + val10 + "  Declare=val11=" + val11 + "  Declare=val12=" + val12 +
                " Declare=val20=" + val20 + "  Declare=val21=" + val21 + "  Declare=val22=" + val22 +
                " Declare=val30=" + val30 + "  Declare=val31=" + val31 + "  Declare=val32=" + val32
            )
            os.system(com2)
def stereo_test():
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

    for i in range(10):
        euler_x = euler[0]
        euler_y = euler[1] + (0.1 * i - 0.4)
        euler_z = euler[2]
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

        t = np.array([[val00, val01, val02, val30],
                      [val10, val11, val12, val31],
                      [val20, val21, val22, val32],
                      [0, 0, 0, 1]], dtype=float)
        right_cam_x = np.matmul(t, np.array([10, 0, 0, 1]).T)
        right_cam_y = np.matmul(t, np.array([0, 10, 0, 1]).T)
        right_cam_z = np.matmul(t, np.array([0, 0, 10, 1]).T)
        left_cam = np.matmul(t, np.array([0, 0, 0, 1]).T)
        list0 = ["left", "right_x", "right_y", "right_z"]
        for cam in list0:
            if cam == "left":
                val30 = str(left_cam[0])
                val31 = str(left_cam[1])
                val32 = str(left_cam[2])
            elif cam == "right_x":
                val30 = str(right_cam_x[0])
                val31 = str(right_cam_x[1])
                val32 = str(right_cam_x[2])
            elif cam == "right_y":
                val30 = str(right_cam_y[0])
                val31 = str(right_cam_y[1])
                val32 = str(right_cam_y[2])
            elif cam == "right_z":
                val30 = str(right_cam_z[0])
                val31 = str(right_cam_z[1])
                val32 = str(right_cam_z[2])
            val00 = str(val00)
            val01 = str(val01)
            val02 = str(val02)
            val10 = str(val10)
            val11 = str(val11)
            val12 = str(val12)
            val20 = str(val20)
            val21 = str(val21)
            val22 = str(val22)
            out_name = str("val_test/stereo_" + cam + "_" + str(i))
            render(path,
                   val00, val01, val02, val10, val11, val12, val20, val21, val22, val30, val31, val32, out_name)
