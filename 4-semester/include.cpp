#include <opencv2>

using namespace cv;

int main()
{
    // �������� �����������
    Mat image = imread("input.jpg");

    // �������� �� �������� �������� �����������
    if (image.empty())
    {
        printf("�� ������� ��������� �����������.\n");
        return -1;
    }

    // �������� ���� ��� ����������� �����������
    namedWindow("Image", WINDOW_NORMAL);
    imshow("Image", image);

    // �������� ������� ������� ��� ������� �������� �������������� ��������
    Rect scratchRect = selectROI(image);

    // �������� ��������
    Mat result = image.clone();
    Mat mask = Mat::zeros(image.size(), CV_8UC1);
    rectangle(mask, scratchRect, Scalar(255), FILLED);
    inpaint(image, mask, result, 3, INPAINT_TELEA);

    // ����������� ����������
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", result);

    // ���������� ����������
    imwrite("output.jpg", result);

    // �������� ������� ������� ��� ���������� ���������
    waitKey(0);

    return 0;
}
