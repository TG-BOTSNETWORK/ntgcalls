//
// Created by Laky64 on 30/09/2023.
//

#pragma once

#include <pc/peer_connection_factory.h>
#include <pc/peer_connection_factory_proxy.h>

namespace wrtc {

    class PeerConnectionFactoryWithContext : public webrtc::PeerConnectionFactory {
    public:
        static rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface> Create(
                webrtc::PeerConnectionFactoryDependencies dependencies,
                rtc::scoped_refptr<webrtc::ConnectionContext>& context);

        PeerConnectionFactoryWithContext(
                webrtc::PeerConnectionFactoryDependencies dependencies);

        PeerConnectionFactoryWithContext(
                rtc::scoped_refptr<webrtc::ConnectionContext> context,
                webrtc::PeerConnectionFactoryDependencies* dependencies);

    private:
        static rtc::scoped_refptr<PeerConnectionFactoryWithContext> Create(
                webrtc::PeerConnectionFactoryDependencies dependencies);

        rtc::scoped_refptr<webrtc::ConnectionContext> GetContext() const;

        rtc::scoped_refptr<webrtc::ConnectionContext> conn_context_;
    };
} // wrtc

