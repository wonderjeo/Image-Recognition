#include"main.h"
int check_shape(char c)
{
	//载入图像、显示并转化为灰度图
	Mat trainImage = imread("fenda.jpg"), trainImage_gray;

	imshow("原始图", trainImage);
	cvtColor(trainImage, trainImage_gray, CV_BGR2GRAY);

	//检测Surf关键点、提取训练图像描述符
	vector<KeyPoint> train_keyPoint;
	Mat trainDescriptor;
	SurfFeatureDetector featureDetector(80);
	featureDetector.detect(trainImage_gray, train_keyPoint);
	SurfDescriptorExtractor featureExtractor;
	featureExtractor.compute(trainImage_gray, train_keyPoint, trainDescriptor);

	//213124214124124124
	FlannBasedMatcher matcher;
	vector<Mat> train_desc_collection(1, trainDescriptor);
	matcher.add(train_desc_collection);
	matcher.train();

	//创建视频对象、定义帧率
	VideoCapture cap(1);
	int count;
	unsigned int frameCount = 0;//帧数

								//【5】不断循环，直到q键被按下
	while (char(waitKey(1)) != 'q')
	{
		//参数设置
		count = 0;
		int64 time0 = getTickCount();
		Mat testImage, testImage_gray;
		cap >> testImage;//采集视频到testImage中
		if (testImage.empty())
			continue;

		//转化图像到灰度
		cvtColor(testImage, testImage_gray, CV_BGR2GRAY);

		//检测S关键点、提取测试图像描述符
		vector<KeyPoint> test_keyPoint;
		Mat testDescriptor;
		featureDetector.detect(testImage_gray, test_keyPoint);
		featureExtractor.compute(testImage_gray, test_keyPoint, testDescriptor);

		//匹配训练和测试描述符
		vector<vector<DMatch> > matches;
		matcher.knnMatch(testDescriptor, matches, 2);

		//根据劳氏算法（Lowe's algorithm），得到优秀的匹配点
		vector<DMatch> goodMatches;
		for (unsigned int i = 0; i < matches.size(); i++)
		{
			if (matches[i][0].distance < 0.6 * matches[i][1].distance)
			{
				goodMatches.push_back(matches[i][0]);
				count++;
				cout << count<<endl;
			}
		}
		if (count > 20)
		{
			cout << "send!!!!!!!!!!!!!!" << endl;
			c_coms();
			c_comn();
			return 1;
		}
		//<6>绘制匹配点并显示窗口
		Mat dstImage;
		drawMatches(testImage, test_keyPoint, trainImage, train_keyPoint, goodMatches, dstImage);
		imshow("匹配窗口", dstImage);
	}

	return 0;
}
