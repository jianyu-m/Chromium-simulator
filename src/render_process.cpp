//
// Created by jianyu on 11/7/16.
//

#include "render_process.hpp"

RenderProcess::RenderProcess() {
    io_thread = new BrowserThread();
    main_thread = new BrowserThread();
}