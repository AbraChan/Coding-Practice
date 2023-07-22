"""
Author: Ping
Date: Jul, 2022
Location: XiaMeiLin, Shenzhen
"""


import tkinter as tk

import tkintertable.Filtering
from tkintertable import TableCanvas, TableModel
from tkinter import messagebox
from tkinter.ttk import Separator


# 专业名称
majors_dict = {"chinese_linguistics": (1, "汉语言学"),
               "english": (2, "英语"),
               "business_english": (3, "商务英语"),
               "spanish": (4, "西班牙语"),
               "portuguese": (5, "葡萄牙语"),
               "science_of_law": (6, "法学"),
               "industry_business_management": (7, "工商管理"),
               "e-commerce": (8, "电子商务"),
               "marketing_sales": (9, "市场营销"),
               "tourism_management": (10, "旅游管理"),
               "fin_tech": (11, "金融科技"),
               "logistics_management": (12, "物流管理"),
               "mba_innovations": (13, "工商管理 (创新班)"),
               "finance_management": (14, "财务管理"),
               "accountancy": (15, "会计学"),
               "accountancy_acca": (16, "会计学 (ACCA卓越班)"),
               "accountancy_cima": (17, "会计学 (CIMA卓越班)"),
               "auditing": (18, "审计学"),
               "administration": (19, "行政管理"),
               "public_relations": (20, "公共关系学"),
               "human_resource_management": (21, "人力资源管理"),
               "communication_studies": (22, "传播学"),
               "social_work": (23, "社会工作"),
               "international_economics_trade": (24, "国际经济与贸易"),
               "economics": (25, "经济学"),
               "economic_statistics": (26, "经济统计学"),
               "taxation": (27, "税收学"),
               "financial_engineering": (28, "金融工程"),
               "investments": (29, "投资学"),
               "internet_finance": (30, "互联网金融"),
               "electronic_information_science_technology": (31, "电子信息科学与技术"),
               "computer_science_technology": (32, "计算机科学与技术"),
               "software_engineering": (33, "软件工程"),
               "digital_media_technology": (34, "数字媒体技术"),
               "electrical_engineering_automation": (35, "电气工程及其自动化"),
               "intelligent_manufacturing_engineering": (36, "智能制造工程"),
               "information_resource_management": (37, "信息资源管理"),
               "health_services_management": (38, "健康服务与管理"),
               "optometry": (39, "眼视光学"),
               "physical_geography_resource_environment": (40, "自然地理与资源环境"),
               "human_geography_urban_rural_planning": (41, "人文地理与城乡规划"),
               "landscape_architecture": (42, "风景园林"),
               "nursing_sciences": (43, "护理学"),
               "biomedical_engineering": (44, "生物医学工程"),
               "medical_imaging": (45, "医学影像技术"),
               "rehabilitation_sciences": (46, "康复治疗学"),
               "hearing_speech_rehabilitation": (47, "听力与言语康复学"),
               "pharmacy": (48, "药学"),
               "internet_new_media": (49, "网络与新媒体"),
               "calligraphy": (50, "书法学"),
               "clothing_and_clothing_design": (51, "服装与服饰设计"),
               "musicology": (52, "音乐学"),
               "Social_PE_guidance_management": (53, "社会体育指导与管理"),}

# 中国省份：23省 5自治区 4直辖市 2特别行政区 (共34个省级行政区)
provinces_dict = {"guanggong": "广东省",
                  "hainan": "海南省",
                  "hunan": "湖南省",
                  # "hubei": "湖北省",
                  "guangxi": "广西",
                  "fujian": "福建省",
                  "jiangxi": "江西省",
                  "sichuan": "四川省",
                  "shandong": "山东省",
                  "jilin": "吉林省",
                  "liaoning": "辽宁省",
                  "henan": "河南省",
                  "anhui": "安徽省",
                  "guizhou": "贵州省",
                  "yunnan": "云南省",
                  "shanxi": "山西省",
                  "shanxi_xian": "陕西省",
                  "chongqing": "重庆市",
                  "jiangsu": "江苏省",
                  # "zhejiang": "浙江省",
                  "hebei": "河北省",
                  "heilongjiang": "黑龙江省",
                  "xizang": "西藏",
                  "xinjiang": "新疆",
                  "ningxia": "宁夏",
                  # "gansu": "甘肃省",
                  # "qinghai": "青海省",
                  # "beijing": "北京市",
                  # "shanghai": "上海市",
                  # "tianjin": "天津市",
                  # # "chongqing": "重庆市",
                  # # "guangxi": "广西",
                  # "neimenggu": "内蒙古",
                  # # "xizang": "西藏",
                  # # "xinjiang": "新疆",
                  # # "ningxia": "宁夏",
                  # "taiwan": "台湾省",
                  # "hongkong": "香港",
                  # "macao": "澳门"
                  }



def save_as_csv():
    print("导出 csv 格式文件成功！")
    messagebox.showinfo(title="提示", message="导出 csv 格式文件成功！")


def import_csv():
    # 先对导入的 csv 文件的结构进行判断是否符合导出的结构
    pass


def exit_ask():
    result = messagebox.askquestion(title="警告", message="不导出为 csv 格式文件就直接推出？")
    # print(type(result), result)    # 输出为：<class 'str'>  和  yes

    if result == 'yes':
        # print("进入 yes")
        root_window.destroy()  # 不用 .quit()，而是用 .destroy()
    else:
        # print("暂不退出。")
        pass


def manual():
    pass


"""
def get_bar_v(*args):
    # print(*args)                      # moveto 0.0
    position = bar_v.get()
    # print(type(position), position)   # <class 'tuple'> (0.0, 0.0, 0.0, 0.0)
"""



def process_data(e):
    print("进入 <Return> 事件处理函数：", type(e), e)
    # print("\tdir(e)：", dir(e))
    print(type(e.widget), e.widget)
    # print(str(e.widget))
    #
    # print(dir(e.widget))          # 'bindtags()', 'cget()', 'children', 'event_info()'
    # print(e.widget.children)      # {}
    # print(e.widget.event_info())  # 输出太复杂了，没有用。
    #
    print(e.widget.bindtags())
    # 输出为：('.!frame.!entry2', 'TEntry', '.', 'all') 或者 ('.!frame2.!frame2.!labelframe.!entry2', 'Entry', '.', 'all')
    #
    # print(e.widget.bindtags()[1], e.widget.bindtags()[1] == "Entry")
    # 因 e.widget.bindtags()[1] 的值为 TEntry 或者 Entry，因此，这里的输出为：
    # TEntry False 或者 Entry True
    # TEntry 表示 tkintertable 里表格的单元格
    # Entry 表示 tkinter 的 Entry 输入控件

    if e.widget.bindtags()[1] == "Entry":  # 表示回车键发生在 tkinter 的 Entry 输入控件里
        return

    # model = table.model
    # my_filter = [("广东 (文)", 0, "=", "OR"), ("广东 (文)", 0, ">", "OR")]

    # print(model.getColumns(colnames=["广东 (文)"], filters=my_filter))    # <class 'list'>，每一个元素也是一个 list。
    # print(model.getColumnData(columnIndex=cols, filters=my_filter))      # <class 'list'>，非嵌套的 。
    # .getColumnData() 也有参数：columnName
    # col_data = list(map(int, col_data))
    # 因为从窗口里输入的数字都会默认被转化为 string 类型，所以通过 map() 来转化。
    # 而且，如果没有 list() 函数来进一步转化的话，会报错：TypeError: 'map' object is not subscriptable

    # col_data = model.getDict(colnames=[col_name], filters=my_filter)     # <class 'dict'>，每一个 key-value 也是自典型。
    # 参数 colnames 的值须为列表。
    # 因为有些列的元素值从 GUI 界面输入后，是 str 类型。且因为前面变量 my_filter 的设定，容易出现报错：
    # TypeError: '>' not supported between instances of 'str' and 'int'
    # 故直接取整个表的数据自己来处理。

    row = table.getSelectedRow()  # 返回的是一个数字，为 row 的索引值。
    col = table.getSelectedColumn()  # 返回的是一个数字，为 row 的索引值。
    # print("row = %d, col = %d" % (row, col))    # 例：row = 2, col = 0
    if row == 0:
        tk.messagebox.showwarning("提示", message='请不要在 “合计” 这一行的任何单元格输入内容。')
        table.model.setValueAt(0, rowIndex=0, columnIndex=col)
        table.redrawTable()
        table.gotonextRow()
        table.gotonextRow()
        return
    if row == 1:
        tk.messagebox.showwarning("提示", message='请不要在第二行空行的任何单元格输入内容。')
        table.model.setValueAt("", rowIndex=1, columnIndex=col)
        table.redrawTable()
        table.gotonextRow()
        return

    row_name = row_names[row - 2]  # 因为 row 是有包含 "合计" 与 "" 这两行在内的排序索引值的。而 row_names 则是不包括的。
    col_name = column_names[col]
    # print("row_name = %s, col_name = %s" % (row_name, col_name))   # 例：row_name = 汉语言学, col_name = 广东 (文)

    # data_all = table.model.data              # 改成放到主函数种去定义
    # print("type(data_all)", type(data_all))  # 嵌套的 <class 'dict'>，每一个 key-value 对应表中的一行 (record)，类型也为 dict。
    # print("data_all", data_all)
    try:
        # print("此单元格的值的类型", type(data_all[row_name][col_name]))    # <class 'int'>
        data_all[row_name][col_name] = int(data_all[row_name][col_name])
    except:
        tk.messagebox.showwarning("提示", message="输入错误，请输入数字！")
        data_all[row_name][col_name] = 0
        return
    col_subjects_sum = 0
    for record_name in row_names:
        # row_names 等于 majors_list，是已经跳过第一行 "合计" 以及 第二行 ""

        # 求col_name 这一列的所有科目招生人数求和。
        cell_value = data_all[record_name][col_name]
        flag_is_str = 0
        if isinstance(cell_value, str):  # 这里最好用正则表达式来判断 cell_value 里全为数字，而没有别的非数字字符
            # print("进入 if isinstance() 分支，\n  cell_value 的值为：", cell_value)
            # print("  cell_value 的类型为：", type(cell_value))
            cell_value = cell_value.strip(" ")  # 去除开头和结尾的 " " 字符
            cell_value = cell_value.lstrip("0")  # 去除开头的 "0" 字符
            if cell_value == "":
                cell_value = 0
            # data_all[record_name][col_name] = int(cell_value)
            flag_is_str = 1
        try:
            if flag_is_str:
                data_all[record_name][col_name] = int(cell_value)
            col_subjects_sum += int(cell_value)
        except ValueError:
            tk.messagebox.showwarning("提示", message="(%s,   %s) 这一单元格的内容格式错误，请更改！" % (record_name, col_name))
            return
    data_all['合计'][col_name] = col_subjects_sum

    ##table.model.setValueAt(sum_col_subjects, 0, columnIndex=col)
    # table.model.setFormulaAt()
    table.redrawTable()

    if e.keysym == "Return":
        # print(e.state, e.keycode)
        # table.gotonextCell(event=e)
        table.gotonextRow()


if __name__ == '__main__':
    majors_list = list(map(lambda t: t[1], sorted(majors_dict.values(), key=lambda v: v[0])))   # 中文名
    provinces_list = list(provinces_dict.values())  # 中文名
    # print(",".join(majors_list))
    # print(",".join(provinces_list))
    # print("," * len(provinces_list))

    # ****** 调用 Tk() 创建主窗口 ******
    root_window = tk.Tk()
    root_window.title("广州新华学院")             # 给主窗口命名为 "广州新华学院"
    root_window.iconbitmap('../images/zf.ico')  # 更改左上角窗口的的 icon 图标，加载广州新华学院 logo

    # window_width = 1280
    # window_height = 720
    # 窗口居中，获取屏幕尺寸以计算布局参数，使窗口居屏幕中央
    screen_width = root_window.winfo_screenwidth()
    screen_height = root_window.winfo_screenheight()
    # size_geo = '%dx%d+%d+%d' % (window_width, window_height, int(screen_width / 2), int(screen_height / 2))
    size_geo = '%dx%d+%d+%d' % (screen_width, screen_height, 0, 0)
    root_window.geometry(size_geo)
    # root_window.attributes("-fullscreen", True)



    # ****** 创建菜单控件 ******
    main_menu = tk.Menu(root_window)  # 创建一个主菜单 (顶级菜单)

    # 在顶级菜单上新增 "文件" 子菜单，同时不添加分割线 (tearoff=False)，注意：分隔线会将此菜单项分离出来成为一个新的窗口
    file_menu = tk.Menu(main_menu, tearoff=False)
    file_menu.add_command(label="导入 csv 文件", command=import_csv, accelerator="Ctrl+I")
    file_menu.add_command(label="保存 csv 文件", command=save_as_csv, accelerator="Ctrl+S")
    # 添加一条分割线，将下面的 "退出" 菜单项与前面的 "新建" 等三个菜单项区分开。
    file_menu.add_separator()
    file_menu.add_command(label="退出", command=exit_ask)
    # 在主目录菜单上新增 "文件" 选项，并通过 menu 参数与下拉菜单绑定
    main_menu.add_cascade(label="文件", menu=file_menu)

    main_menu.add_command(label="说明", command=manual, accelerator="Ctrl+M")

    # main_menu.pack()    # 报错：TclError: can't pack ".!menu": it's a top-level window
    # 将主菜单设置在窗口上
    root_window.config(menu=main_menu)

    # 绑定键盘事件，按下键盘上的相应的键时都会触发执行函数
    # root_window.bind("<Control-n>", menuCommand)    # 函数 menuCommand 需另行定义。
    # root_window.bind("<Control-N>", menuCommand)
    root_window.bind("<Control-E>", save_as_csv)



    # ****** 顶部标签 ******
    label_top = tk.Label(root_window,
                         text="招生计划求解器",
                         font=("雅黑", 18),
                         bg="LightSeaGreen",
                         width=108, height=1,
                         )
    label_top.grid(row=0, column=0, sticky=tk.W)  # sticky=tk.N+tk.S+tk.W+tk.E



    # """
    # ****** 表格 ******
    frame_details = tk.Frame(root_window)
    frame_details.place(relx=0, rely=0.41, relwidth=1, relheight=0.58)

    # *** 使用 tkintertable 库实现表格
    row_names = majors_list
    column_names = []
    data_initial = {}
    for m in ["合计", ""] + majors_list:
        data_initial[m] = {}
        if m == "":
            continue
        for p in provinces_list:
            p = p[:-1] if "省" in p or "市" in p else p
            if p in ["海南", "山东"]:
                data_initial[m][p + " (综)"] = int(0)
                column_names.append(p + " (综)")
            else:
                data_initial[m][p + " (文)"] = int(0)
                data_initial[m][p + " (理)"] = int(0)
                column_names.append(p + " (文)")
                column_names.append(p + " (理)")
    model = TableModel()
    table = TableCanvas(frame_details,
                        model, data=data_initial,
                        showkeynamesinheader=True,
                        cellwidth=70, cellbackgr='#e3f698',  # LightSeaGreen
                        # grid_color="gray",
                        thefont=('雅黑', 9),  # ('Arial', 12)
                        rowheight=18, rowheaderwidth=120,
                        rowselectedcolor='yellow',
                        editable=True)
    table.show()
    table.gotonextRow()
    table.gotonextRow()
    data_all = table.model.data

    # print("table.model.getDefaultTypes(): ", table.model.getDefaultTypes())    # 输出：['text', 'number']

    root_window.bind("<Return>", process_data)
    root_window.bind("<Up>", process_data)
    root_window.bind("<Down>", process_data)
    root_window.bind("<Left>", process_data)
    root_window.bind("<Right>", process_data)

    # tk.messagebox.showinfo("提示", message="请在各单元格中输入内容之后，按回车键，确保输入内容及时被刷新！")
    # """


    # ****** 各省份计划与剩余 ******
    frame_plan = tk.Frame(root_window)  # , width=1280, height=210)
    # 在 Frame() 通过参数 width 和 height 设置尺寸毫无意义，尺寸最终由其子控件的相应维度的最大值决定。
    frame_plan.grid(row=1, column=0, sticky=tk.W, pady=8)
    # frame_plan.grid_propagate(False)
    # 需要固定的组件在其初始化时设置好大小(width=xx,height=xx)，然后在 grid 时使用grid_propagate(0)禁止扩张即可。

    # 课程类别
    frame_plan_category = tk.Frame(frame_plan)  # bg="pink"
    frame_plan_category.grid(row=0, column=0, sticky=tk.W, padx=3)
    category = ["文    科", "理    科", "综合改革", "美    术", "音    乐", "体    育"]
    for i, c in enumerate(category):
        tk.Label(frame_plan_category,
                 text=c, font=("雅黑", 11,),
                 width=8, height=1,
                 bg="LightSeaGreen").grid(row=i, column=0, pady=4)
    frame_plan_province = tk.Frame(frame_plan, bg="LightCyan")
    frame_plan_province.grid(row=0, column=1, padx=6)
    # 广东省计划
    labelframe_guangdong = tk.LabelFrame(frame_plan_province,
                                         text="广东省计划",
                                         labelanchor="n",  # 参数 labelanchor 设置标题方位
                                         bg="LightCyan",
                                         font=("雅黑", 11, "bold"),
                                         width=120, height=215)
    labelframe_guangdong.grid(row=0, column=0, padx=3)
    labelframe_guangdong.grid_propagate(False)
    # 外省计划
    labelframe_waisheng = tk.LabelFrame(frame_plan_province,
                                        text="外省计划",
                                        labelanchor="n",  # 参数 labelanchor 设置标题方位
                                        bg="LightCyan",  # LightSeaGreen：浅海洋绿。 PowderBlue：粉蓝色(火药青)。
                                        font=("雅黑", 11, "bold"),
                                        width=120, height=215)
    labelframe_waisheng.grid(row=0, column=1, padx=3)
    labelframe_waisheng.grid_propagate(False)

    # tk.Entry() 变量，类型为动态字符串。
    # 广东省计划
    dystr_guangdong_wenke = tk.StringVar()
    dystr_guangdong_like = tk.StringVar()
    dystr_guangdong_zonghe = tk.StringVar()
    dystr_guangdong_meishu = tk.StringVar()
    dystr_guangdong_yinyue = tk.StringVar()
    dystr_guangdong_tiyu = tk.StringVar()
    guangdong_plan = [dystr_guangdong_wenke, dystr_guangdong_like, dystr_guangdong_zonghe,
                      dystr_guangdong_meishu, dystr_guangdong_yinyue, dystr_guangdong_tiyu]
    # 外省计划汇总
    dystr_waisheng_wenke = tk.StringVar()
    dystr_waisheng_like = tk.StringVar()
    dystr_waisheng_zonghe = tk.StringVar()
    dystr_waisheng_meishu = tk.StringVar()
    dystr_waisheng_yinyue = tk.StringVar()
    dystr_waisheng_tiyu = tk.StringVar()
    waisheng_plan = [dystr_waisheng_wenke, dystr_waisheng_like, dystr_waisheng_zonghe,
                     dystr_waisheng_meishu, dystr_waisheng_yinyue, dystr_waisheng_tiyu]

    plan_entry_label_mapto_subject_dict = {}
    for lf, p in zip([labelframe_guangdong, labelframe_waisheng], [guangdong_plan, waisheng_plan]):
        for i, c in enumerate(category):
            entry = tk.Entry(lf, width=6, textvariable=p[i], validate="focusout", validatecommand="none", )
            label = tk.Label(lf, width=5, height=1, textvariable=p[i], bg="pink", fg="green")

            if lf == labelframe_guangdong and c == "综合改革":
                label.config(text="", bg="LightCyan", fg='green',)
                label.grid(row=2, column=0, padx=3, pady=4)
                # 广东省没有 “综合改革”，因此对应的这个 entry 没有进行 grid()
            else:
                entry.grid(row=i, column=0, padx=3, pady=4)
                label.grid(row=i, column=2, )


            """
            if lf == labelframe_guangdong and c == "综合改革":
                tk.Label(lf, width=5, height=1,
                         text="", bg="LightCyan", fg='green', ).grid(row=2, column=0, padx=3, pady=4)
            else:
                entry = tk.Entry(lf, width=6, textvariable=p[i], validate="focusout", validatecommand="none",)
                entry.grid(row=i, column=0, padx=3, pady=4)
                label = tk.Label(lf, width=5, height=1, textvariable=p[i], bg="pink", fg="green")
                label.grid(row=i, column=2,)
            """


        label_remain = tk.Label(lf, text="余:", width=2, height=1, font=("雅黑", 9,), bg="LightCyan", fg="maroon")
        label_remain.grid(row=0, column=1, pady=5)

    # 外省详情
    # 把 frame 放在 canvas 里面（比如填满整个canvas），canvas 与 scrollbar 结合，这样滚动 canvas 就等于滚动 frame 了。
    # 参考链接：https://blog.csdn.net/qq_28123095/article/details/79331756
    canvas = tk.Canvas(frame_plan,
                       width=930, height=210,  # sticky=tk.N+tk.S+tk.E+tk.W 时这两个参数无效。
                       bg="green",
                       scrollregion=(0, 0, 2020, 460), )
    canvas.grid(row=0, column=2, sticky=tk.N + tk.W)  # , sticky=tk.N+tk.S+tk.E+tk.W)
    # 当设置 sticky=tk.N+tk.S+tk.E+tk.W 时，即向 4 个方向的填充，延伸，此时，
    # canvas 的 width 由其子控件最大的 width 决定， canvas 的 height 由其父控件的 height 决定。
    canvas.grid_propagate(False)
    # 需要固定的组件在其初始化时设置好大小(width=xx,height=xx)，然后在 grid 时使用grid_propagate(0)禁止扩张即可。

    frame_plan_province_details = tk.Frame(canvas, width=2020, height=460)  #, bg="pink")
    frame_plan_province_details.grid(row=0, column=2)  # , sticky=tk.N+tk.S+tk.E+tk.W)
    frame_plan_province_details.grid_propagate(False)

    id_ = canvas.create_window((1010, 230), window=frame_plan_province_details)
    # 参数 (900, 230) 的坐标为相对于 root_window 而言的。(平：这句话可能是错的！)
    # print("id_ 为：", id_)

    # 海南
    dystr_hainan_wenke = tk.StringVar()
    dystr_hainan_like = tk.StringVar()
    dystr_hainan_zonghe = tk.StringVar()
    dystr_hainan_meishu = tk.StringVar()
    dystr_hainan_yinyue = tk.StringVar()
    dystr_hainan_tiyu = tk.StringVar()
    # 湖南
    dystr_hunan_wenke = tk.StringVar()
    dystr_hunan_like = tk.StringVar()
    dystr_hunan_zonghe = tk.StringVar()
    dystr_hunan_meishu = tk.StringVar()
    dystr_hunan_yinyue = tk.StringVar()
    dystr_hunan_tiyu = tk.StringVar()
    # 广西
    dystr_guangxi_wenke = tk.StringVar()
    dystr_guangxi_like = tk.StringVar()
    dystr_guangxi_zonghe = tk.StringVar()
    dystr_guangxi_meishu = tk.StringVar()
    dystr_guangxi_yinyue = tk.StringVar()
    dystr_guangxi_tiyu = tk.StringVar()
    # 福建
    dystr_fujian_wenke = tk.StringVar()
    dystr_fujian_like = tk.StringVar()
    dystr_fujian_zonghe = tk.StringVar()
    dystr_fujian_meishu = tk.StringVar()
    dystr_fujian_yinyue = tk.StringVar()
    dystr_fujian_tiyu = tk.StringVar()
    # 江西
    dystr_jiangxi_wenke = tk.StringVar()
    dystr_jiangxi_like = tk.StringVar()
    dystr_jiangxi_zonghe = tk.StringVar()
    dystr_jiangxi_meishu = tk.StringVar()
    dystr_jiangxi_yinyue = tk.StringVar()
    dystr_jiangxi_tiyu = tk.StringVar()
    # 四川
    dystr_sichuan_wenke = tk.StringVar()
    dystr_sichuan_like = tk.StringVar()
    dystr_sichuan_zonghe = tk.StringVar()
    dystr_sichuan_meishu = tk.StringVar()
    dystr_sichuan_yinyue = tk.StringVar()
    dystr_sichuan_tiyu = tk.StringVar()
    # 山东
    dystr_shandong_wenke = tk.StringVar()
    dystr_shandong_like = tk.StringVar()
    dystr_shandong_zonghe = tk.StringVar()
    dystr_shandong_meishu = tk.StringVar()
    dystr_shandong_yinyue = tk.StringVar()
    dystr_shandong_tiyu = tk.StringVar()
    # 吉林
    dystr_jilin_wenke = tk.StringVar()
    dystr_jilin_like = tk.StringVar()
    dystr_jilin_zonghe = tk.StringVar()
    dystr_jilin_meishu = tk.StringVar()
    dystr_jilin_yinyue = tk.StringVar()
    dystr_jilin_tiyu = tk.StringVar()
    # 辽宁
    dystr_liaoning_wenke = tk.StringVar()
    dystr_liaoning_like = tk.StringVar()
    dystr_liaoning_zonghe = tk.StringVar()
    dystr_liaoning_meishu = tk.StringVar()
    dystr_liaoning_yinyue = tk.StringVar()
    dystr_liaoning_tiyu = tk.StringVar()
    # 河南
    dystr_henan_wenke = tk.StringVar()
    dystr_henan_like = tk.StringVar()
    dystr_henan_zonghe = tk.StringVar()
    dystr_henan_meishu = tk.StringVar()
    dystr_henan_yinyue = tk.StringVar()
    dystr_henan_tiyu = tk.StringVar()
    # 安徽
    dystr_anhui_wenke = tk.StringVar()
    dystr_anhui_like = tk.StringVar()
    dystr_anhui_zonghe = tk.StringVar()
    dystr_anhui_meishu = tk.StringVar()
    dystr_anhui_yinyue = tk.StringVar()
    dystr_anhui_tiyu = tk.StringVar()
    # 贵州
    dystr_guizhou_wenke = tk.StringVar()
    dystr_guizhou_like = tk.StringVar()
    dystr_guizhou_zonghe = tk.StringVar()
    dystr_guizhou_meishu = tk.StringVar()
    dystr_guizhou_yinyue = tk.StringVar()
    dystr_guizhou_tiyu = tk.StringVar()
    # 云南
    dystr_yunnan_wenke = tk.StringVar()
    dystr_yunnan_like = tk.StringVar()
    dystr_yunnan_zonghe = tk.StringVar()
    dystr_yunnan_meishu = tk.StringVar()
    dystr_yunnan_yinyue = tk.StringVar()
    dystr_yunnan_tiyu = tk.StringVar()
    # 山西
    dystr_shanxi_taiyuan_wenke = tk.StringVar()
    dystr_shanxi_taiyuan_like = tk.StringVar()
    dystr_shanxi_taiyuan_zonghe = tk.StringVar()
    dystr_shanxi_taiyuan_meishu = tk.StringVar()
    dystr_shanxi_taiyuan_yinyue = tk.StringVar()
    dystr_shanxi_taiyuan_tiyu = tk.StringVar()
    # 陕西
    dystr_shanxi_xian_wenke = tk.StringVar()
    dystr_shanxi_xian_like = tk.StringVar()
    dystr_shanxi_xian_zonghe = tk.StringVar()
    dystr_shanxi_xian_meishu = tk.StringVar()
    dystr_shanxi_xian_yinyue = tk.StringVar()
    dystr_shanxi_xian_tiyu = tk.StringVar()
    # 重庆
    dystr_chongqing_wenke = tk.StringVar()
    dystr_chongqing_like = tk.StringVar()
    dystr_chongqing_zonghe = tk.StringVar()
    dystr_chongqing_meishu = tk.StringVar()
    dystr_chongqing_yinyue = tk.StringVar()
    dystr_chongqing_tiyu = tk.StringVar()
    # 江苏
    dystr_jaingsu_wenke = tk.StringVar()
    dystr_jaingsu_like = tk.StringVar()
    dystr_jaingsu_zonghe = tk.StringVar()
    dystr_jaingsu_meishu = tk.StringVar()
    dystr_jaingsu_yinyue = tk.StringVar()
    dystr_jaingsu_tiyu = tk.StringVar()
    # 河北
    dystr_hebei_wenke = tk.StringVar()
    dystr_hebei_like = tk.StringVar()
    dystr_hebei_zonghe = tk.StringVar()
    dystr_hebei_meishu = tk.StringVar()
    dystr_hebei_yinyue = tk.StringVar()
    dystr_hebei_tiyu = tk.StringVar()
    # 黑龙江
    dystr_heilongjiang_wenke = tk.StringVar()
    dystr_heilongjiang_like = tk.StringVar()
    dystr_heilongjiang_zonghe = tk.StringVar()
    dystr_heilongjiang_meishu = tk.StringVar()
    dystr_heilongjiang_yinyue = tk.StringVar()
    dystr_heilongjiang_tiyu = tk.StringVar()
    # 西藏
    dystr_xizang_wenke = tk.StringVar()
    dystr_xizang_like = tk.StringVar()
    dystr_xizang_zonghe = tk.StringVar()
    dystr_xizang_meishu = tk.StringVar()
    dystr_xizang_yinyue = tk.StringVar()
    dystr_xizang_tiyu = tk.StringVar()
    # 新疆
    dystr_xinjiang_wenke = tk.StringVar()
    dystr_xinjiang_like = tk.StringVar()
    dystr_xinjiang_zonghe = tk.StringVar()
    dystr_xinjiang_meishu = tk.StringVar()
    dystr_xinjiang_yinyue = tk.StringVar()
    dystr_xinjiang_tiyu = tk.StringVar()
    # 宁夏
    dystr_ningxia_wenke = tk.StringVar()
    dystr_ningxia_like = tk.StringVar()
    dystr_ningxia_zonghe = tk.StringVar()
    dystr_ningxia_meishu = tk.StringVar()
    dystr_ningxia_yinyue = tk.StringVar()
    dystr_ningxia_tiyu = tk.StringVar()

    waisheng_plan_respectively = [[dystr_hainan_wenke, dystr_hainan_like, dystr_hainan_zonghe,
                                   dystr_hainan_meishu, dystr_hainan_yinyue, dystr_hainan_tiyu],

                                  [dystr_hunan_wenke, dystr_hunan_like, dystr_hunan_zonghe,
                                   dystr_hunan_meishu, dystr_hunan_yinyue, dystr_hunan_tiyu],

                                  [dystr_guangxi_wenke, dystr_guangxi_like, dystr_guangxi_zonghe,
                                   dystr_guangxi_meishu, dystr_guangxi_yinyue, dystr_guangxi_tiyu],

                                  [dystr_fujian_wenke, dystr_fujian_like, dystr_fujian_zonghe,
                                   dystr_fujian_meishu, dystr_fujian_yinyue, dystr_fujian_tiyu],

                                  [dystr_jiangxi_wenke, dystr_jiangxi_like, dystr_jiangxi_zonghe,
                                   dystr_jiangxi_meishu, dystr_jiangxi_yinyue, dystr_jiangxi_tiyu],

                                  [dystr_sichuan_wenke, dystr_sichuan_like, dystr_sichuan_zonghe,
                                   dystr_sichuan_meishu, dystr_sichuan_yinyue, dystr_sichuan_tiyu],

                                  [dystr_shandong_wenke, dystr_shandong_like, dystr_shandong_zonghe,
                                   dystr_shandong_meishu, dystr_shandong_yinyue, dystr_shandong_tiyu],

                                  [dystr_jilin_wenke, dystr_jilin_like, dystr_jilin_zonghe,
                                   dystr_jilin_meishu, dystr_jilin_yinyue, dystr_jilin_tiyu],

                                  [dystr_liaoning_wenke, dystr_liaoning_like, dystr_liaoning_zonghe,
                                   dystr_liaoning_meishu, dystr_liaoning_yinyue, dystr_liaoning_tiyu],

                                  [dystr_henan_wenke, dystr_henan_like, dystr_henan_zonghe,
                                   dystr_henan_meishu, dystr_henan_yinyue, dystr_henan_tiyu],

                                  [dystr_anhui_wenke, dystr_anhui_like, dystr_anhui_zonghe,
                                   dystr_anhui_meishu, dystr_anhui_yinyue, dystr_anhui_tiyu],

                                  [dystr_guizhou_wenke, dystr_guizhou_like, dystr_guizhou_zonghe,
                                   dystr_guizhou_meishu, dystr_guizhou_yinyue, dystr_guizhou_tiyu],

                                  [dystr_yunnan_wenke, dystr_yunnan_like, dystr_yunnan_zonghe,
                                   dystr_yunnan_meishu, dystr_yunnan_yinyue, dystr_yunnan_tiyu],

                                  [dystr_shanxi_taiyuan_wenke, dystr_shanxi_taiyuan_like, dystr_shanxi_taiyuan_zonghe,
                                   dystr_shanxi_taiyuan_meishu, dystr_shanxi_taiyuan_yinyue, dystr_shanxi_taiyuan_tiyu],

                                  [dystr_shanxi_xian_wenke, dystr_shanxi_xian_like, dystr_shanxi_xian_zonghe,
                                   dystr_shanxi_xian_meishu, dystr_shanxi_xian_yinyue, dystr_shanxi_xian_tiyu],

                                  [dystr_chongqing_wenke, dystr_chongqing_like, dystr_chongqing_zonghe,
                                   dystr_chongqing_meishu, dystr_chongqing_yinyue, dystr_chongqing_tiyu],

                                  [dystr_jaingsu_wenke, dystr_jaingsu_like, dystr_jaingsu_zonghe,
                                   dystr_jaingsu_meishu, dystr_jaingsu_yinyue, dystr_jaingsu_tiyu],

                                  [dystr_hebei_wenke, dystr_hebei_like, dystr_hebei_zonghe,
                                   dystr_hebei_meishu, dystr_hebei_yinyue, dystr_hebei_tiyu],

                                  [dystr_heilongjiang_wenke, dystr_heilongjiang_like, dystr_heilongjiang_zonghe,
                                   dystr_heilongjiang_meishu, dystr_heilongjiang_yinyue, dystr_heilongjiang_tiyu],

                                  [dystr_xizang_wenke, dystr_xizang_like, dystr_xizang_zonghe,
                                   dystr_xizang_meishu, dystr_xizang_yinyue, dystr_xizang_tiyu],

                                  [dystr_xinjiang_wenke, dystr_xinjiang_like, dystr_xinjiang_zonghe,
                                   dystr_xinjiang_meishu, dystr_xinjiang_yinyue, dystr_xinjiang_tiyu],

                                  [dystr_ningxia_wenke, dystr_ningxia_like, dystr_ningxia_zonghe,
                                   dystr_ningxia_meishu, dystr_ningxia_yinyue, dystr_ningxia_tiyu]]

    for i, (province, plan) in enumerate(zip(provinces_list[1:], waisheng_plan_respectively)):
        lf = tk.LabelFrame(frame_plan_province_details,
                           text=province[:-1] if "省" in province or "市" in province else province, font=("雅黑", 10,),
                           labelanchor="n",       # 参数 labelanchor 设置标题方位
                           width=22, height=1,
                           bg="LightCyan" if i%2==0 else "LightCyan")
        lf.grid(row=0, column=i, padx=5)
        for j in range(len(category)):
            tk.Entry(lf, width=3, textvariable=plan[j],
                     validate="focusout", validatecommand="待定", ).grid(row=j, column=0, padx=2, pady=4)
            tk.Label(lf, width=3, height=1, textvariable=plan[j],
                     bg="pink", fg="green").grid(row=j, column=2, padx=2)

        label_remain = tk.Label(lf, text="余:",
                                width=2, height=1, font=("雅黑", 8,), bg="LightCyan", fg="maroon")
        label_remain.grid(row=0, column=1, pady=5)


    # 添加 Scrollbar 滚动条控件
    bar_h = tk.Scrollbar(frame_plan, width=20, orient=tk.HORIZONTAL)  # 创建一个滚动条控件，默认为垂直方向
    # bar_h.grid(row=1, column=0, sticky=tk.N+tk.S+tk.E+tk.W, columnspan=3)
    # bar_h.place(relx=0.265, rely=0.92, relwidth=0.72)  # relwidth=0.72 是不与右边竖直滚动条(下面被注释掉了)相重合。
    bar_h.place(relx=0.265, rely=0.92, relwidth=0.74)
    bar_h.configure(command=canvas.xview)
    canvas.configure(xscrollcommand=bar_h.set)


    """
    # ****** 表格 ******
    frame_details = tk.Frame(root_window)
    frame_details.place(relx=0, rely=0.41, relwidth=1, relheight=0.58)

    # *** 使用 tkintertable 库实现表格
    row_names = majors_list
    column_names = []
    data_initial = {}
    for m in ["合计", ""] + majors_list:
        data_initial[m] = {}
        if m == "":
            continue
        for p in provinces_list:
            p = p[:-1] if "省" in p or "市" in p else p
            if p in ["海南", "山东"]:
                data_initial[m][p+" (综)"] = int(0)
                column_names.append(p+" (综)")
            else:
                data_initial[m][p+" (文)"] = int(0)
                data_initial[m][p+" (理)"] = int(0)
                column_names.append(p+" (文)")
                column_names.append(p+" (理)")
    model = TableModel()
    table = TableCanvas(frame_details,
                        model, data=data_initial,
                        showkeynamesinheader=True,
                        cellwidth=70, cellbackgr='#e3f698',  # LightSeaGreen
                        # grid_color="gray",
                        thefont=('雅黑', 9),                  # ('Arial', 12)
                        rowheight=18, rowheaderwidth=120,
                        rowselectedcolor='yellow',
                        editable=True)
    table.show()
    table.gotonextRow()
    table.gotonextRow()

    # print("table.model.getDefaultTypes(): ", table.model.getDefaultTypes())    # 输出：['text', 'number']


    root_window.bind("<Return>", process_data)
    root_window.bind("<Up>", process_data)
    root_window.bind("<Down>", process_data)
    root_window.bind("<Left>", process_data)
    root_window.bind("<Right>", process_data)
    
    """

    tk.messagebox.showinfo("提示", message="请在各单元格中输入内容之后，按回车键，确保输入内容及时被刷新！")


    # 开启主循环，让窗口处于显示状态
    root_window.mainloop()
