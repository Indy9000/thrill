/*******************************************************************************
 * thrill/io/request_queue.hpp
 *
 * Copied and modified from STXXL https://github.com/stxxl/stxxl, which is
 * distributed under the Boost Software License, Version 1.0.
 *
 * Part of Project Thrill - http://project-thrill.org
 *
 * Copyright (C) 2009 Andreas Beckmann <beckmann@cs.uni-frankfurt.de>
 * Copyright (C) 2011 Johannes Singler <singler@ira.uka.de>
 *
 * All rights reserved. Published under the BSD-2 license in the LICENSE file.
 ******************************************************************************/

#pragma once
#ifndef THRILL_IO_REQUEST_QUEUE_HEADER
#define THRILL_IO_REQUEST_QUEUE_HEADER

#include <thrill/common/defines.hpp>
#include <thrill/io/request.hpp>

namespace thrill {
namespace io {

//! \addtogroup io_layer_req
//! \{

//! Interface of a request_queue to which requests can be added and canceled.
class RequestQueue
{
public:
    enum PriorityOp { READ, WRITE, NONE };

    RequestQueue() = default;

    //! non-copyable: delete copy-constructor
    RequestQueue(const RequestQueue&) = delete;
    //! non-copyable: delete assignment operator
    RequestQueue& operator = (const RequestQueue&) = delete;
    //! move-constructor: default
    RequestQueue(RequestQueue&&) = default;
    //! move-assignment operator: default
    RequestQueue& operator = (RequestQueue&&) = default;

public:
    virtual void AddRequest(RequestPtr& req) = 0;
    virtual bool CancelRequest(Request* req) = 0;
    virtual ~RequestQueue() { }
    virtual void SetPriorityOp(PriorityOp p) { common::UNUSED(p); }
};

//! \}

} // namespace io
} // namespace thrill

#endif // !THRILL_IO_REQUEST_QUEUE_HEADER

/******************************************************************************/
