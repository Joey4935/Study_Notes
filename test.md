# 
定义一个结构体，保存一个位置。这个结构体可以在经纬度以及Range变化后被更改。更改后平板以及主地球的位置都设置为该位置。

# 结构体

```
struct CurrentPos
{
	//-1	没有未处理的位置变化     
	//0		平板处位置变化 
	//1		主地球处位置发生变化
	int m_iWhoChange;
	//
	double m_dEyeTerrainPos_x;
	double m_dEyeTerrainPos_y;
	double m_dEyeTerrainPos_z;
	//
	double m_dEyeDistance;
    //
	CurrentPos()
	{
		m_iWhoChange = -1;
		m_dEyeTerrainPos_x = 0;
		m_dEyeTerrainPos_y = 0;
		m_dEyeTerrainPos_z = 0;
		m_dEyeDistance = 0;
	}
};
```
当```m_iWhoChange == 0```时，改变主地球位置。


当```m_iWhoChange == 1```时，改变平板位置。

# 何时经纬度以及range发生变化

## 平板 

手动操作

## 主地球  

方案演播

目标跳转

# 实现
