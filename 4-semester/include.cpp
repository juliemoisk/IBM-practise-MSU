#include <opencv2>

using namespace cv;

int main()
{
    // Загрузка изображения
    Mat image = imread("input.jpg");

    // Проверка на успешную загрузку изображения
    if (image.empty())
    {
        printf("Не удалось загрузить изображение.\n");
        return -1;
    }

    // Создание окна для отображения изображения
    namedWindow("Image", WINDOW_NORMAL);
    imshow("Image", image);

    // Ожидание нажатия клавиши для ручного указания местоположения царапины
    Rect scratchRect = selectROI(image);

    // Удаление царапины
    Mat result = image.clone();
    Mat mask = Mat::zeros(image.size(), CV_8UC1);
    rectangle(mask, scratchRect, Scalar(255), FILLED);
    inpaint(image, mask, result, 3, INPAINT_TELEA);

    // Отображение результата
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", result);

    // Сохранение результата
    imwrite("output.jpg", result);

    // Ожидание нажатия клавиши для завершения программы
    waitKey(0);

    return 0;
}
