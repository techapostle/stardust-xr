#ifndef STARDUSTOPENXRFRAME_H
#define STARDUSTOPENXRFRAME_H


#include "openxr_meta.h"
#include "stardustopenxrgraphics.h"

class StardustOpenXRFrame : public QObject
{
    Q_OBJECT
    Q_PROPERTY(StardustOpenXRGraphics *graphics MEMBER graphics)
public:
    explicit StardustOpenXRFrame(QObject *parent = nullptr);

    StardustOpenXRGraphics *graphics = nullptr;
    QThread *thread = nullptr;

signals:
    void initialized();

    void startedFrame();

    void renderedFrame();

    void frameEnded();

public slots:
    void initialize();

private slots:
    void startFrame();

    void renderFrame();

    void endFrame();

private:
    void copyFrame();
    void initRenderControl();

    //Vulkan helper functions
    VkCommandBuffer beginSingleTimeCommands(uint32_t count);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    void createEXTBuffers();
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &bufferMemory, int &fd, VkMemoryRequirements &memRequirements);

    //Vulkan variables
    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    VkDeviceSize imageSize;
    VkMemoryRequirements memRequirements;
    int fd = 0;

    //OpenGL helper functions
    void createTextureFromFD(int d);

    //OpenGL variables
    GLuint copyFBO;
    GLuint colorTex;
};

#endif // STARDUSTOPENXRFRAME_H
