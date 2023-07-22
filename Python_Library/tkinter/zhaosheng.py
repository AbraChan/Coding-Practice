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


def refresh_entry_and_label(entry, t_entry=0):
    """t_entry: bool，用于表示该 entry 是 TEntry 控件还是 普通的 Entry 控件。
            当 entry 是 TEntry 控件 或者 "广东省计划" 里的 Entry时，无需更新 “外省计划” 里的 Entry。
    """

    try:
        entry_value = int(entry.get())
    except ValueError:
        entry_value = 0
        if t_entry == 1:
            entry.configure(textvariable=tk.StringVar(value=0))
            # entry.focus_set()
            tk.messagebox.showinfo("提示", message="请在上方先输入该省各个类别的招生计划")
        if t_entry == 0:
            tk.messagebox.showwarning("提示", message="输入错误，请输入数字！")
            entry.focus_set()  # 输入光标回到当前 widget。

    entry_name = str(entry)

    province, category = entry_name_dict[entry_name][0], entry_name_dict[entry_name][1]
    # print(labelframe_object_dict[province].winfo_children().index(event.widget))
    print("进入 refresh_entry_and_label() 函数，省份为：", province, "\tt_entry=", t_entry, "\tentry 为：", entry)
    if province != "外省":  # table 里没有 "外省" 这一列。只要不是 "外省"，不管是何种 entry，就需要对非 "外省计划" 里的相关 Label 进行处理。
        index = entry_name_list.index(entry_name)
        label_object = label_object_list[index]
        column_sum = 0
        if province in ["海南", "山东"]:  # 因为这两个省在 table 里只有一列。
            if category == "综":
                column_sum = data_all["合计"][province + " (综)"]
            elif category == "美":  # 美、书、音、体
                column_sum = data_all["服装与服饰设计"][province + " (综)"]
            elif category == "书":
                column_sum = data_all["书法学"][province + " (综)"]
            elif category == "音":
                column_sum = data_all["音乐学"][province + " (综)"]
            else:          # "体"
                column_sum = data_all["社会体育指导与管理"][province + " (综)"]
            label_object.configure(textvariable=tk.StringVar(value=entry_value - column_sum))

        else:  # 剩余的省份都没有 "综" 这一 列、Entry。
            if category == "文" or category == "理":
                column_sum = data_all["合计"][province + " (%s)" % category]
            elif category == "综":
                pass
            elif category == "美":
                column_sum += data_all["服装与服饰设计"][province + " (文)"]
                column_sum += data_all["服装与服饰设计"][province + " (理)"]
            elif category == "书":
                column_sum += data_all["书法学"][province + " (文)"]
                column_sum += data_all["书法学"][province + " (理)"]
            elif category == "音":
                column_sum += data_all["音乐学"][province + " (文)"]
                column_sum += data_all["音乐学"][province + " (理)"]
            else:          # "体"
                column_sum += data_all["社会体育指导与管理"][province + " (文)"]
                column_sum += data_all["社会体育指导与管理"][province + " (理)"]
            label_object.configure(textvariable=tk.StringVar(value=entry_value - column_sum))
        if entry_value - column_sum < 0:
            # !!! 这里一移动鼠标总是会弹出对话框，需要进一步处理！
            tk.messagebox.showwarning("警告", message="此专业所属类别的该省招收人数之和已经超过该省 “计划” 里设定的人数。")

    if t_entry == 0:
        print("=" * 99)
        if province == "广东":
            return

        lf_waisheng = labelframe_object_dict["外省"]
        entry_index = ["文", "理", "综", "美", "书", "音", "体"].index(category) * 2
        entry_of_waisheng = lf_waisheng.winfo_children()[entry_index]
        label_of_waisheng = lf_waisheng.winfo_children()[entry_index + 1]
        # print("entry_of_waisheng: ", entry_of_waisheng)
        # print("label_of_waisheng: ", label_of_waisheng)
        value_entry_of_waisheng = entry_of_waisheng.get()
        if value_entry_of_waisheng == "":
            value_entry_of_waisheng = 0
            tk.messagebox.showinfo("提示", '”外省计划“ 里对应的学科类别还未输入相应的计划人数，最好先输入！')
        else:
            value_entry_of_waisheng = int(value_entry_of_waisheng)

        # 将所有非广东省的其他省的 LabelFrame 里的 对应的 Entry 里的值相加。
        sum_all_waisheng = 0
        keys = list(labelframe_object_dict.keys())
        print("list[labelframe_object_dict.keys()][2:]: ", keys)
        print("value_entry_of_waisheng: ", value_entry_of_waisheng)
        for p in keys[2:]:  # 跳过 "广东" 和 "外省"
            lf = labelframe_object_dict[p]
            entry_other_province = lf.winfo_children()[entry_index]
            sum_all_waisheng += 0 if entry_other_province.get() == '' else int(entry_other_province.get())
        print("sum_all_waisheng: ", sum_all_waisheng)
        label_of_waisheng.configure(textvariable=tk.StringVar(value=value_entry_of_waisheng - sum_all_waisheng))
        if value_entry_of_waisheng - sum_all_waisheng < 0:
            # !!! 这里一移动鼠标总是会弹出对话框，需要进一步处理！
            tk.messagebox.showwarning("警告", message="该专业所属类别的各省计划人数之和已经超过 “外省计划” 里设定的人数。")
        print("*" * 99)



def process_table_data(event):
    print("进入 process_table_data 函数：", type(event), event)

    row = table.getSelectedRow()     # 返回的是一个数字，为 row 的索引值。
    col = table.getSelectedColumn()  # 返回的是一个数字，为 row 的索引值。
    if row == 0:
        table.model.setValueAt(0, rowIndex=0, columnIndex=col)
        if str(event.type) == "FocusOut" or str(event.type) == "Motion" or event.keysym == "Return":
            table.setSelectedCells(row+1, row+1, col, col)
            table.gotonextRow()
        table.redrawTable()
        table.show()
        tk.messagebox.showwarning("提示", message='请不要在 “合计” 这一行的任何单元格输入内容。')
        return
    if row == 1:
        table.model.setValueAt("", rowIndex=1, columnIndex=col)
        if str(event.type) == "FocusOut" or str(event.type) == "Motion" or event.keysym == "Return":
            table.gotonextRow()
        table.redrawTable()
        table.show()
        tk.messagebox.showwarning("提示", message='请不要在第二行空行的任何单元格输入内容。')
        return

    row_name = row_names[row - 2]  # 因为 row 是有包含 "合计" 与 "" 这两行在内的排序索引值的。而 row_names 则是不包括的。
    col_name = column_names[col]
    try:
        # print("此单元格的值的类型", type(data_all[row_name][col_name]))    # <class 'int'>
        data_all[row_name][col_name] = int(data_all[row_name][col_name])
    except ValueError:
        data_all[row_name][col_name] = 0
        table.redrawTable()
        table.show()
        tk.messagebox.showwarning("提示", message="输入错误，请输入数字！")
        return

    col_subjects_sum = 0
    for record_name in row_names[:-4]:
        # row_names 等于 majors_list，是已经跳过第一行 "合计" 以及 第二行 ""
        # row_names 的最后四行分别对应 "书"、"美"、"音"、"体" 这四个专业。

        # 求col_name 这一列的所有文科、理科或综合类别的招生人数之和。
        cell_value = data_all[record_name][col_name]
        flag_is_str = 0
        if isinstance(cell_value, str):  # 这里最好用正则表达式来判断 cell_value 里全为数字，而没有别的非数字字符
            cell_value = cell_value.strip(" ")  # 去除开头和结尾的 " " 字符
            cell_value = cell_value.lstrip("0")  # 去除开头的 "0" 字符
            if cell_value == "":
                cell_value = 0
            flag_is_str = 1
        try:
            if flag_is_str:
                data_all[record_name][col_name] = int(cell_value)
            col_subjects_sum += int(cell_value)
        except ValueError:
            data_all[record_name][col_name] = 0
            table.redrawTable()
            table.show()
            tk.messagebox.showwarning("提示", message="(%s,   %s) 这一单元格的内容为：%s。\n"
                                                     "格式错误，已置为 0，请重新录入数字！" % (record_name, col_name, cell_value))
            return

    data_all['合计'][col_name] = col_subjects_sum
    table.redrawTable()

    if event.keysym == "Return":
        table.gotonextRow()

    if str(event.type) == "FocusOut":  # or str(event.type) == "Motion":
        if str(event.widget) == ".!frame.!tablecanvas" or str(event.widget) == ".!frame.!entry2":
            pass
        return

    # 更新 Entry 控件及其对应的 Label
    print(event.widget, event.widget.bindtags())
    province = col_name[:2]
    category = col_name[-2]
    if row_name in ["书法学", "服装与服饰设计", "音乐学", "社会体育指导与管理"]:
        if row_name == "服装与服饰设计":
            category = "美"
        elif row_name == "书法学":
            category = "书"
        elif row_name == "音乐学":
            category = "音"
        else:
            category = "体"
    print(province, ":", category)
    lf = labelframe_object_dict[province]
    entry_index = ["文", "理", "综", "美", "书", "音", "体"].index(category) * 2
    entry = lf.winfo_children()[entry_index]
    refresh_entry_and_label(entry, t_entry=1)

    # if event.keysym == "Return":
    #     table.gotonextRow()

    # table.show()



def events_handler(event):
    # 函数 events_handler 绑定的事件的 event.keysym 包括：["??", "Return", "Up", "Down", "Right", "Left"]
    # 其中 event.keysym = "??" 对应 <FocusOut> 事件。

    # print(root_window.focus_get())                        # .!frame.!entry2
    # print(event.type, type(event.type), str(event.type))  # Motion <enum 'EventType'> Motion
    # print(widget_name)

    # print(list(map(lambda x:len(x.winfo_children()), labelframe_object_dict.values())))
    # [15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15]
    # 总共 24 个 15。

    widget_name = str(event.widget)
    if ("entry" not in widget_name) and ("tablecanvas" not in widget_name):
        return

    if "labelframe" in widget_name:       # LabelFrame 里的 Entry
        if str(event.type) == "Motion":
            return

        print("处理 LabelFrame 里的 Entry...")
        # print(event.widget)
        # print(event.widget.winfo_parent())
        # print(root_window.nametowidget(event.widget.winfo_parent()).winfo_children())
        entry_value = event.widget.get()    # <class 'str'>
        if entry_value == "":
            return

        refresh_entry_and_label(event.widget, t_entry=0)

    else:    # Table 里的 Entry
        print("处理 Table 里的 Entry ...")
        process_table_data(event)



if __name__ == '__main__':

    majors_list = list(map(lambda t: t[1], sorted(majors_dict.values(), key=lambda v: v[0])))   # 中文名
    provinces_list = list(provinces_dict.values())  # 中文名
    # print(",".join(majors_list))
    # print(",".join(provinces_list))


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
    root_window.bind("<Control-E>", save_as_csv)   # 函数 save_as_csv 需另行定义。

    # 函数 focusout 绑定的事件的 event.keysym 包括：["??", "Return", "Up", "Down", "Right", "Left"]
    # 其中 event.keysym = "??" 对应 <FocusOut> 事件。
    root_window.bind("<FocusOut>", events_handler)    # 鼠标光标离开控件实例
    root_window.bind("<Motion>", events_handler)      # 鼠标移动
    root_window.bind("<Return>", events_handler)
    root_window.bind("<Up>", events_handler)
    root_window.bind("<Down>", events_handler)
    root_window.bind("<Left>", events_handler)
    root_window.bind("<Right>", events_handler)



    # ****** 顶部标签 ******
    label_top = tk.Label(root_window,
                         text="招生计划求解器",
                         font=("雅黑", 18),
                         bg="LightSeaGreen",
                         width=108, height=1,
                         )
    label_top.grid(row=0, column=0, sticky=tk.W)  # sticky=tk.N+tk.S+tk.W+tk.E



    # ****** 表格 ******
    frame_table = tk.Frame(root_window)
    frame_table.place(relx=0, rely=0.48, relwidth=1, relheight=0.52)

    # *** 使用 tkintertable 库实现表格
    row_names = majors_list
    column_names = []
    data_initial = {}
    flag_appended_column_name = 0
    for m in ["合计", ""] + majors_list:
        data_initial[m] = {}
        if m == "":
            continue
        for p in provinces_list:
            p = p[:-1] if "省" in p or "市" in p else p
            if p in ["海南", "山东"]:
                data_initial[m][p + " (综)"] = int(0)
                if flag_appended_column_name == 0:
                    column_names.append(p + " (综)")
            else:
                data_initial[m][p + " (文)"] = int(0)
                data_initial[m][p + " (理)"] = int(0)
                if flag_appended_column_name == 0:
                    column_names.append(p + " (文)")
                    column_names.append(p + " (理)")
        flag_appended_column_name = 1

    column_names_waisheng = column_names.copy()     # 不含 “广东” 或者 “综” 的列名
    for c in ["广东 (文)", "广东 (理)", "海南 (综)", "山东 (综)"]:
        column_names_waisheng.remove(c)

    model = TableModel()
    table = TableCanvas(frame_table,
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



    # ****** 各省份计划与剩余 ******
    frame_plan = tk.Frame(root_window)  # , width=1280, height=210)
    # 在 Frame() 通过参数 width 和 height 设置尺寸毫无意义，尺寸最终由其子控件的相应维度的最大值决定。
    frame_plan.grid(row=1, column=0, sticky=tk.W, pady=15)
    # frame_plan.grid_propagate(False)
    # 需要固定的组件在其初始化时设置好大小(width=xx,height=xx)，然后在 grid 时使用grid_propagate(0)禁止扩张即可。

    # 课程类别
    frame_plan_category = tk.Frame(frame_plan, width=70, height=245)  # bg="pink"
    frame_plan_category.grid(row=0, column=0, sticky=tk.W, padx=3)
    frame_plan_category.grid_propagate(False)
    category = ["文    科",  "理    科",  "综合改革",  "美    术",  "书    法",  "音    乐",  "体    育"]
    tk.Label(frame_plan_category, text="", font=("雅黑", 3,),
             width=8, height=1).grid(row=0, column=0, pady=4)
    for i, c in enumerate(category):
        tk.Label(frame_plan_category,
                 text=c, font=("雅黑", 11,),
                 width=8, height=1,
                 bg="LightSeaGreen").grid(row=i+1, column=0, pady=4)
    frame_plan_province = tk.Frame(frame_plan, bg="LightCyan")
    frame_plan_province.grid(row=0, column=1, padx=6)
    # 广东省计划
    labelframe_guangdong = tk.LabelFrame(frame_plan_province,
                                         text="广东省计划",
                                         labelanchor="n",  # 参数 labelanchor 设置标题方位
                                         bg="LightCyan",
                                         font=("雅黑", 11, "bold"),
                                         width=120, height=245)    # height=215 -> 245
    labelframe_guangdong.grid(row=0, column=0, padx=3)
    labelframe_guangdong.grid_propagate(False)
    # 外省计划
    labelframe_waisheng = tk.LabelFrame(frame_plan_province,
                                        text="外省计划",
                                        labelanchor="n",  # 参数 labelanchor 设置标题方位
                                        bg="LightCyan",  # LightSeaGreen：浅海洋绿。 PowderBlue：粉蓝色(火药青)。
                                        font=("雅黑", 11, "bold"),
                                        width=120, height=245)
    labelframe_waisheng.grid(row=0, column=1, padx=3)
    labelframe_waisheng.grid_propagate(False)

    """
    print(str(frame_plan))              # .!frame2
    print(frame_plan.winfo_name())      # !frame2
    print(frame_plan.winfo_parent())    # .
    print(frame_plan.winfo_children())  # [<tkinter.Frame object .!frame2.!frame>, <tkinter.Frame object .!frame2.!frame2>]
    print(frame_plan.winfo_id())        # 8528486
    
    print(frame_plan.nametowidget(str(frame_plan)))                # .!frame2
    print(type(frame_plan.nametowidget(str(frame_plan))))          # <class 'tkinter.Frame'>
    print(frame_plan.nametowidget(str(frame_plan)).winfo_name())   # !frame2
    
    print("type(frame_plan.winfo_parent()): ", type(frame_plan.winfo_parent()))   # <class 'str'>
    print(type(root_window.nametowidget(frame_plan.winfo_parent())))              # <class 'tkinter.Tk'>
    print(type(frame_plan.nametowidget(frame_plan.winfo_parent())))               # <class 'tkinter.Tk'>
    """

    entry_name_dict = {}
    # entry_object_dict = {}
    # entry_name_list 在第591行定义，通过 list(entry_name_dict.keys()) 得到。
    label_object_list = []
    # label_name_dict = {}
    labelframe_object_dict = {}

    for lf in [labelframe_guangdong, labelframe_waisheng]:
        for i, c in enumerate(category):
            # entry = tk.Entry(lf, width=6, textvariable=p[i], validate="key", validatecommand="none", )
            entry = tk.Entry(lf, width=6, textvariable=tk.StringVar(value=""), validate="key", validatecommand="none")
            label = tk.Label(lf, width=5, height=1, textvariable=tk.StringVar(value=""), bg="pink", fg="green")

            if lf == labelframe_guangdong and c == "综合改革":    # 这一步操作是将此 entry 与 label 进行隐形，方便布局的美观。
                label.config(bg="LightCyan", fg='green')
                label.grid(row=2, column=0, padx=3, pady=4)
                # 广东省没有 “综合改革”，因此对应的这个 entry 没有进行 grid()，也就相当于隐形了。
            else:
                entry.grid(row=i, column=0, padx=3, pady=4)
                label.grid(row=i, column=2, )

            entry_name = entry.bindtags()[0]
            label_name = label.bindtags()[0]

            if lf == labelframe_guangdong:
                if i == 0:
                    entry.focus_set()  # 将输入光标初始位置设置在 "广东省计划" 的 "文科" 的位置。

                # c[0] 为 ["文", "理", "综", "美", "书", "音", "体"] 里的元素之一
                entry_name_dict[entry_name] = ["广东", c[0]]
                # label_object_list.append(label)
                # label_object_dict[label] = ["外省", c[0]]
                # label_name_dict[label_name] = ["广东", c[0]]
                labelframe_object_dict["广东"] = lf
            else:
                entry_name_dict[entry_name] = ["外省", c[0]]
                # label_object_list.append(label)
                # label_object_dict[label] = ["外省", c[0]]
                # label_name_dict[label_name] = ["广东", c[0]]
                labelframe_object_dict["外省"] = lf

            label_object_list.append(label)

        label_yu = tk.Label(lf, text="余:", width=2, height=1, font=("雅黑", 9,), bg="LightCyan", fg="maroon")
        label_yu.grid(row=0, column=1, pady=5)


    # 外省详情
    # 把 frame 放在 canvas 里面（比如填满整个canvas），canvas 与 scrollbar 结合，这样滚动 canvas 就等于滚动 frame 了。
    # 参考链接：https://blog.csdn.net/qq_28123095/article/details/79331756
    canvas = tk.Canvas(frame_plan, width=930, height=245, bg="green", scrollregion=(0, 0, 2020, 460))
    canvas.grid(row=0, column=2, sticky=tk.N + tk.W)
    # 当设置 sticky=tk.N+tk.S+tk.E+tk.W 时，即向 4 个方向的填充，延伸，此时，
    # canvas 的 width 由其子控件最大的 width 决定， canvas 的 height 由其父控件的 height 决定。
    canvas.grid_propagate(False)
    # 需要固定的组件在其初始化时设置好大小(width=xx,height=xx)，然后在 grid 时使用grid_propagate(0)禁止扩张即可。

    frame_plan_province_details = tk.Frame(canvas, width=2020, height=460)
    frame_plan_province_details.grid(row=0, column=2)
    frame_plan_province_details.grid_propagate(False)

    id_ = canvas.create_window((1010, 230), window=frame_plan_province_details)
    # 参数 (900, 230) 的坐标为相对于 root_window 而言的。(平：这句话可能是错的！)
    # print("id_ 为：", id_)

    # for i, (province, plan) in enumerate(zip(provinces_list[1:], waisheng_plan_respectively)):
    for i, province in enumerate(provinces_list[1:]):
        province = province[:-1] if "省" in province or "市" in province else province
        lf = tk.LabelFrame(frame_plan_province_details,
                           text=province, font=("雅黑", 10,),
                           labelanchor="n",       # 参数 labelanchor 设置标题方位
                           width=22, height=1,
                           bg="LightCyan" if i%2==0 else "LightCyan")
        lf.grid(row=0, column=i, padx=5, pady=3)

        labelframe_object_dict[province] = lf

        for j in range(len(category)):
            entry = tk.Entry(lf, width=3, textvariable=tk.StringVar(value=""), validate="focusout", validatecommand="none")
            label = tk.Label(lf, width=3, height=1, textvariable=tk.StringVar(value=""), bg="pink", fg="green")

            if province in ["海南", "山东"] and j in [0, 1]:    # 不放置文科和理科的 Entry 控件。
                label.grid(row=j, column=2, padx=2, pady=4)
            else:
                entry.grid(row=j, column=0, padx=2, pady=4)
                label.grid(row=j, column=2, padx=2)

            entry_name = entry.bindtags()[0]
            label_name = label.bindtags()[0]

            # category[j][0] 为 ["文", "理", "综", "美", "书", "音", "体"] 里的元素之一
            entry_name_dict[entry_name] = [province, category[j][0]]
            label_object_list.append(label)

        label_yu = tk.Label(lf, text="余:", width=2, height=1, font=("雅黑", 8,), bg="LightCyan", fg="maroon")
        label_yu.grid(row=0, column=1, pady=5)
        """
        if province in ["海南", "山东"]:
            label_yu.grid(row=2, column=1, pady=5)
        else:
            label_yu.grid(row=0, column=1, pady=5)
        """

    entry_name_list = list(entry_name_dict.keys())
    # print(len(entry_name_dict))     # 168
    # print(len(label_object_list))   # 168

    # 添加 Scrollbar 滚动条控件
    bar_h = tk.Scrollbar(frame_plan, width=20, orient=tk.HORIZONTAL)  # 创建一个滚动条控件，默认为垂直方向
    # bar_h.grid(row=1, column=0, sticky=tk.N+tk.S+tk.E+tk.W, columnspan=3)
    # bar_h.place(relx=0.265, rely=0.92, relwidth=0.72)  # relwidth=0.72 是不与右边竖直滚动条(下面被注释掉了)相重合。
    bar_h.place(relx=0.265, rely=0.92, relwidth=0.74)
    bar_h.configure(command=canvas.xview)
    canvas.configure(xscrollcommand=bar_h.set)

    # tk.messagebox.showinfo("提示", message="请在各单元格中输入内容之后，按回车键，确保输入内容及时被刷新！")

    # 开启主循环，让窗口处于显示状态
    root_window.mainloop()
