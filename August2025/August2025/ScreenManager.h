#pragma once

class ScreenManager
{
public:
	static ScreenManager& getInstance();

	void setDimensions(int t_width, int t_height);

	template<typename T>
	T getWidth() {
		return T(m_width);  
	}

	template<typename T>
	T getHeight() {
		return T(m_height);
	}

private:
	ScreenManager() = default;

	int m_width = 1920;
	int m_height = 1280;
};

